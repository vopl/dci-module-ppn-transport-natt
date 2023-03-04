/* This file is part of the the dci project. Copyright (C) 2013-2023 vopl, shtoba.
   This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public
   License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
   This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty
   of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Affero General Public License for more details.
   You should have received a copy of the GNU Affero General Public License along with this program. If not, see <https://www.gnu.org/licenses/>. */

#pragma once

#include "pch.hpp"
#include "../netBased/lookout.hpp"
#include "service.hpp"

namespace dci::module::ppn::transport::natt::mapper::igdp
{
    class Lookout
        : public mapper::netBased::Lookout<Lookout, Service>
    {
    public:
        Lookout(Mapper* mapper);
        ~Lookout() override;

        cmt::Waitable* regularTicker();
        void regularTick();

    public:
        void mcastReceived(Bytes&& data, const net::Endpoint& senderEp);

    public:
        static constexpr uint16             _mcastListenPort    = 1900;
        static constexpr Array<uint8, 4>    _mcastListenAddr4   = {239,255,255,250};
        static constexpr Array<uint8, 16>   _mcastListenAddr6   = {0xff,0x02,0,0,0,0,0,0,0,0,0,0,0,0,0,1};

        static constexpr uint16             _servicePort        = 1900;

    private:
        poll::WaitableTimer<> _regularTicker {std::chrono::milliseconds{1000*60}, true};
    };
}
