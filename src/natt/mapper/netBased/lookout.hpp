/* This file is part of the the dci project. Copyright (C) 2013-2023 vopl, shtoba.
   This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public
   License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
   This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty
   of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Affero General Public License for more details.
   You should have received a copy of the GNU Affero General Public License along with this program. If not, see <https://www.gnu.org/licenses/>. */

#pragma once

#include "pch.hpp"
#include "../lookout.hpp"

namespace dci::module::ppn::transport::natt::mapper::netBased
{
    template <class MostLookout, class MostService>
    class Lookout
        : public mapper::Lookout
    {
    public:
        Lookout(Mapper* mapper);
        ~Lookout() override;

        const net::Host<>& netHost();

        cmt::Waitable* regularTicker();
        void regularTick();

    protected:
        void worker();
        void updateMcastListeners();
        std::deque<net::IpAddress> linkAddressesFor(const net::IpAddress& addr);
        void updateServices();

    protected:
        using Gateways = std::set<net::IpAddress>;
        using LinkId = uint32;
        struct Link
        {
            sbs::Owner  _sol;
            LinkId      _id {};
            net::Link<> _api;
        };
        using Links = std::map<LinkId, Link>;
        using LinkAddresses4 = Set<net::link::Ip4Address>;
        using LinkAddresses6 = Set<net::link::Ip6Address>;

    protected:
        sbs::Owner          _sol;
        cmt::task::Owner    _tol;

    protected:
        net::Host<>     _netHost;
        Gateways        _gateways;
        Links           _links;
        LinkAddresses4  _linkAddresses4;
        LinkAddresses6  _linkAddresses6;
        cmt::Pulser     _netChanged;

    protected:
        struct McastListner
        {
            net::datagram::Channel<>    _ch;
            sbs::Owner                  _sol;
        };
        McastListner                    _mcastListner4;
        std::map<LinkId, McastListner>  _mcastListners6;

    protected:
        using ServiceAddr = std::tuple<net::IpAddress, net::Endpoint>;//client, server

        std::map<ServiceAddr, MostService>    _services;
    };
}
