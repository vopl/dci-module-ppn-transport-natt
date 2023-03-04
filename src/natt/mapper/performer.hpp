/* This file is part of the the dci project. Copyright (C) 2013-2023 vopl, shtoba.
   This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public
   License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
   This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty
   of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Affero General Public License for more details.
   You should have received a copy of the GNU Affero General Public License along with this program. If not, see <https://www.gnu.org/licenses/>. */

#pragma once

#include "pch.hpp"

namespace dci::module::ppn::transport::natt::mapper
{
    class Performer
    {
    public:
        Performer();
        virtual ~Performer();

        virtual bool start() = 0;
        virtual bool keepalive() = 0;
        virtual void stop() = 0;

        const apit::Address& external() const;

    protected:
        apit::Address _external;
    };

    using PerformerPtr = std::unique_ptr<Performer, void(*)(Performer*)>;
}
