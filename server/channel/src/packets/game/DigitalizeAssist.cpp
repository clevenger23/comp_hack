/**
 * @file server/channel/src/packets/game/DigitalizeAssist.cpp
 * @ingroup channel
 *
 * @author HACKfrost
 *
 * @brief Request from the client for the current player's digitalize
 *  assist skills.
 *
 * This file is part of the Channel Server (channel).
 *
 * Copyright (C) 2012-2018 COMP_hack Team <compomega@tutanota.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as
 * published by the Free Software Foundation, either version 3 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "Packets.h"

// libcomp Includes
#include <Packet.h>
#include <PacketCodes.h>

// object Includes
#include <CharacterProgress.h>

// channel Includes
#include "ChannelClientConnection.h"

using namespace channel;

bool Parsers::DigitalizeAssist::Parse(libcomp::ManagerPacket *pPacketManager,
    const std::shared_ptr<libcomp::TcpConnection>& connection,
    libcomp::ReadOnlyPacket& p) const
{
    (void)pPacketManager;

    if(p.Size() != 4)
    {
        return false;
    }

    int32_t unknown = p.ReadS32Little();
    (void)unknown;  // Always 0

    auto client = std::dynamic_pointer_cast<ChannelClientConnection>(
        connection);
    auto state = client->GetClientState();
    auto cState = state->GetCharacterState();
    auto character = cState->GetEntity();
    auto progress = character ? character->GetProgress().Get() : nullptr;
    
    libcomp::Packet reply;
    reply.WritePacketCode(ChannelToClientPacketCode_t::PACKET_DIGITALIZE_ASSIST);
    reply.WriteS32Little(0);    // Unknown
    reply.WriteS32Little(progress ? 0 : -1);

    if(progress)
    {
        auto assist = progress->GetDigitalizeAssists();
        reply.WriteS16Little((int16_t)assist.size());
        reply.WriteArray(&assist, (uint32_t)assist.size());
    }

    client->SendPacket(reply);

    return true;
}
