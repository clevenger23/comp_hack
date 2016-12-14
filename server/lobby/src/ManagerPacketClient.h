/**
 * @file server/lobby/src/ManagerPacketClient.cpp
 * @ingroup lobby
 *
 * @author HACKfrost
 *
 * @brief Manager to handle client lobby packets.
 *
 * This file is part of the lobby Server (lobby).
 *
 * Copyright (C) 2012-2016 COMP_hack Team <compomega@tutanota.com>
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

#ifndef LIBCOMP_SRC_MANAGERPACKETCLIENT_H
#define LIBCOMP_SRC_MANAGERPACKETCLIENT_H

// channel Includes
#include "ManagerPacket.h"

namespace lobby
{
class ManagerPacketClient : public ManagerPacket
{
public:
    ManagerPacketClient(const std::shared_ptr<libcomp::BaseServer>& server);
    virtual ~ManagerPacketClient();
};

} // namespace channel

#endif // LIBCOMP_SRC_MANAGERPACKETCLIENT_H