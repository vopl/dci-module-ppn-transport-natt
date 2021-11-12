/* This file is part of the the dci project. Copyright (C) 2013-2021 vopl, shtoba.
   This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public
   License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
   This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty
   of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Affero General Public License for more details.
   You should have received a copy of the GNU Affero General Public License along with this program. If not, see <https://www.gnu.org/licenses/>. */

#pragma once

#include "pch.hpp"

namespace dci::module::ppn::transport::natt::addr
{
    std::string toString(const net::Endpoint& v);
    std::string toString(const net::IpEndpoint& v);
    std::string toString(const net::Ip4Endpoint& v);
    std::string toString(const net::Ip6Endpoint& v);

    std::string toString(const net::IpAddress& v);
    std::string toString(const net::Ip4Address& v);
    std::string toString(const net::Ip6Address& v);

    std::string toString(api::Protocol p);
    std::string toString(const net::Endpoint& v, api::Protocol p);
    std::string toString(const net::IpEndpoint& v, api::Protocol p);
    std::string toString(const net::Ip4Endpoint& v, api::Protocol p);
    std::string toString(const net::Ip6Endpoint& v, api::Protocol p);

    std::string toString(const net::IpAddress& v, api::Protocol p);
    std::string toString(const net::Ip4Address& v, api::Protocol p);
    std::string toString(const net::Ip6Address& v, api::Protocol p);

    bool fromString(const std::string& str, api::Protocol& p, net::IpEndpoint& ep);
}
