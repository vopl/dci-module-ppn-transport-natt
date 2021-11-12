/* This file is part of the the dci project. Copyright (C) 2013-2021 vopl, shtoba.
   This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public
   License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
   This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty
   of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Affero General Public License for more details.
   You should have received a copy of the GNU Affero General Public License along with this program. If not, see <https://www.gnu.org/licenses/>. */

#pragma once

#include "pch.hpp"
#include "service.hpp"

namespace dci::module::ppn::transport::natt
{
    class Mapper;
}

namespace dci::module::ppn::transport::natt::mapper
{
    class Lookout
    {
    public:
        Lookout(Mapper* mapper);
        virtual ~Lookout();

        PerformerBlank candidate(const apit::Address& internal);

    public:
        bool activate(Service* s);
        bool deactivate(Service* s);

        Mapper* mapper();

    private:
        Mapper* _mapper;
        std::set<Service*> _services;
    };
}
