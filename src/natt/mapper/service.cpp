/* This file is part of the the dci project. Copyright (C) 2013-2022 vopl, shtoba.
   This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public
   License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
   This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty
   of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Affero General Public License for more details.
   You should have received a copy of the GNU Affero General Public License along with this program. If not, see <https://www.gnu.org/licenses/>. */

#include "pch.hpp"
#include "service.hpp"

namespace dci::module::ppn::transport::natt::mapper
{
    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    Service::Service()
    {
    }

    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    Service::~Service()
    {
    }

    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    const std::string& Service::name() const
    {
        return _name;
    }

}
