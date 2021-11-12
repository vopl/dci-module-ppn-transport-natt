/* This file is part of the the dci project. Copyright (C) 2013-2021 vopl, shtoba.
   This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public
   License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
   This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty
   of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Affero General Public License for more details.
   You should have received a copy of the GNU Affero General Public License along with this program. If not, see <https://www.gnu.org/licenses/>. */

#pragma once

#include "pch.hpp"
#include "../performer.hpp"

namespace dci::module::ppn::transport::natt::mapper::custom
{
    class Lookout;
    class Performer
        : public mapper::Performer
    {
    public:
        Performer(Lookout* l, const apit::Address& internal);
        ~Performer() override;

        bool start() override;
        bool keepalive() override;
        void stop() override;

    private:
        bool fetch();

    private:
        Lookout *       _l;
        std::size_t     _revision{};
        apit::Address   _internal;
    };
}
