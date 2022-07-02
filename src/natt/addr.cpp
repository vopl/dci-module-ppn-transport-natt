/* This file is part of the the dci project. Copyright (C) 2013-2022 vopl, shtoba.
   This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public
   License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
   This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty
   of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Affero General Public License for more details.
   You should have received a copy of the GNU Affero General Public License along with this program. If not, see <https://www.gnu.org/licenses/>. */

#include "pch.hpp"
#include "addr.hpp"

namespace dci::module::ppn::transport::natt::addr
{
    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    std::string toString(const net::Endpoint& v)
    {
        if(v.holds<net::NullEndpoint>())
        {
            return {};
        }
        if(v.holds<net::Ip4Endpoint>())
        {
            return toString(v.get<net::Ip4Endpoint>());
        }
        if(v.holds<net::Ip6Endpoint>())
        {
            return toString(v.get<net::Ip6Endpoint>());
        }
        if(v.holds<net::LocalEndpoint>())
        {
            return v.get<net::LocalEndpoint>().address;
        }

        return {};
    }

    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    std::string toString(const net::IpEndpoint& v)
    {
        if(v.holds<net::Ip4Endpoint>())
        {
            return toString(v.get<net::Ip4Endpoint>());
        }

        return toString(v.get<net::Ip6Endpoint>());
    }

    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    std::string toString(const net::Ip4Endpoint& v)
    {
        return utils::net::ip::toString(v.address.octets, v.port);
    }

    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    std::string toString(const net::Ip6Endpoint& v)
    {
        return utils::net::ip::toString(v.address.octets, v.address.linkId, v.port);
    }

    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    std::string toString(const net::IpAddress& v)
    {
        if(v.holds<net::Ip4Address>())
        {
            return toString(v.get<net::Ip4Address>());
        }

        return toString(v.get<net::Ip6Address>());
    }

    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    std::string toString(const net::Ip4Address& v)
    {
        return utils::net::ip::toString(v.octets);
    }

    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    std::string toString(const net::Ip6Address& v)
    {
        return utils::net::ip::toString(v.octets, v.linkId);
    }

    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    std::string toString(api::Protocol p)
    {
        if(api::Protocol::udp == p)
        {
            return "udp";
        }

        return "tcp";
    }

    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    std::string toString(const net::Endpoint& v, api::Protocol p)
    {
        if(v.holds<net::NullEndpoint>())
        {
            return "null://";
        }
        if(v.holds<net::Ip4Endpoint>())
        {
            return toString(v.get<net::Ip4Endpoint>(), p);
        }
        if(v.holds<net::Ip6Endpoint>())
        {
            return toString(v.get<net::Ip6Endpoint>(), p);
        }
        if(v.holds<net::LocalEndpoint>())
        {
            return "local://" + v.get<net::LocalEndpoint>().address;
        }
        return "unknown://";
    }

    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    std::string toString(const net::IpEndpoint& v, api::Protocol p)
    {
        if(v.holds<net::Ip4Endpoint>())
        {
            return toString(v.get<net::Ip4Endpoint>(), p);
        }

        return toString(v.get<net::Ip6Endpoint>(), p);
    }

    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    std::string toString(const net::Ip4Endpoint& v, api::Protocol p)
    {
        return toString(p) + "4://" + toString(v);
    }

    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    std::string toString(const net::Ip6Endpoint& v, api::Protocol p)
    {
        return toString(p) + "6://" + toString(v);
    }

    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    std::string toString(const net::IpAddress& v, api::Protocol p)
    {
        if(v.holds<net::Ip4Address>())
        {
            return toString(v.get<net::Ip4Address>(), p);
        }

        return toString(v.get<net::Ip6Address>(), p);
    }

    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    std::string toString(const net::Ip4Address& v, api::Protocol p)
    {
        return toString(p) + "4://" + toString(v);
    }

    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    std::string toString(const net::Ip6Address& v, api::Protocol p)
    {
        return toString(p) + "6://[" + toString(v) + "]";
    }

    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    bool fromString(const std::string& str, api::Protocol& p, net::IpEndpoint& ep)
    {
        auto scheme = utils::net::url::scheme(str);
        auto authority = utils::net::url::authority(str);

        if(scheme == "tcp4" || scheme == "tcp6")
        {
            p = api::Protocol::tcp;
        }
        else if(scheme == "udp4" || scheme == "udp6")
        {
            p = api::Protocol::udp;
        }
        else
        {
            return false;
        }

        if('4' == scheme.back())
        {
            net::Ip4Endpoint& ep4 = ep.sget<net::Ip4Endpoint>();
            return utils::net::ip::fromString(authority, ep4.address.octets, ep4.port);
        }

        net::Ip6Endpoint& ep6 = ep.sget<net::Ip6Endpoint>();
        return utils::net::ip::fromString(authority, ep6.address.octets, ep6.address.linkId, ep6.port);
    }
}
