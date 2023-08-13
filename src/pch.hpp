/* This file is part of the the dci project. Copyright (C) 2013-2023 vopl, shtoba.
   This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public
   License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
   This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty
   of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Affero General Public License for more details.
   You should have received a copy of the GNU Affero General Public License along with this program. If not, see <https://www.gnu.org/licenses/>. */

#pragma once

#include <dci/host.hpp>
#include <dci/config.hpp>
#include <dci/poll/timer.hpp>
#include <dci/utils/uri.hpp>
#include <dci/utils/ip.hpp>
#include <dci/utils/atScopeExit.hpp>
#include <dci/utils/b2h.hpp>
#include <dci/utils/s2f.hpp>
#include <dci/utils/endian.hpp>
#include <dci/poll/waitableTimer.hpp>
#include <mutex> //std::lock_guard
#include <regex>
#include <functional>
#include <charconv>
#include <experimental/random>
#include "ppn/transport/natt.hpp"

namespace dci::module::ppn::transport
{
    using namespace dci;

    namespace net   = idl::net;
    namespace ppn   = idl::ppn;
    namespace apit  = idl::ppn::transport;
    namespace api   = idl::ppn::transport::natt;
}
