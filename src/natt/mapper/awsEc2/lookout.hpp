/* This file is part of the the dci project. Copyright (C) 2013-2022 vopl, shtoba.
   This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public
   License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
   This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty
   of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Affero General Public License for more details.
   You should have received a copy of the GNU Affero General Public License along with this program. If not, see <https://www.gnu.org/licenses/>. */

#pragma once

#include "pch.hpp"
#include "../lookout.hpp"
#include "../service.hpp"
#include "../performer.hpp"

namespace dci::module::ppn::transport::natt::mapper::awsEc2
{
    class Lookout
        : public mapper::Lookout
        , private mapper::Service
    {
    public:
        Lookout(Mapper* mapper);
        ~Lookout() override;

        PerformerBlank candidate(const apit::Address& internal) override;

        const net::Ip4Address& internal() const;
        const net::Ip4Address& external() const;
        std::size_t revision() const;
        cmt::Waitable& changed();

    private:
        void reveal();
        net::Ip4Address requestIp(net::stream::Client<> client, const std::string& path);

    private:
        net::Ip4Address _internal;
        net::Ip4Address _external;
        std::size_t     _revision{};
        cmt::Pulser     _changed;

    private:
        cmt::task::Owner    _tol;
        poll::Timer         _revealTicker{std::chrono::minutes{10}, true, [this]{reveal();}, &_tol};
        std::size_t         _revealDepth {};

    };
}
