/* This file is part of the the dci project. Copyright (C) 2013-2023 vopl, shtoba.
   This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public
   License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
   This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty
   of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Affero General Public License for more details.
   You should have received a copy of the GNU Affero General Public License along with this program. If not, see <https://www.gnu.org/licenses/>. */

#pragma once

#include "pch.hpp"
#include "mapper/lookout.hpp"
#include "mapper/performer.hpp"

namespace dci::module::ppn::transport::natt
{
    class Mapping;
    class Mapper
    {
    public:
        Mapper(dci::host::module::Entry* module);
        ~Mapper();

        template <class L>
        L* add(auto&&... args);

        api::Mapping<> alloc();

        host::Manager* hostManager();
        host::module::StopLocker hostModuleStopLocker();

        void lookoutChanged(mapper::Lookout* l);

    private:
        friend class Mapping;
        void start(Mapping* mapping);
        void stop(Mapping* mapping);

    private:
        mapper::PerformerPtr performerFor(const apit::Address& internal);//in thread

    private:
        dci::host::module::Entry* _module;

        using LookoutPtr = std::unique_ptr<mapper::Lookout>;
        std::set<LookoutPtr>                    _lookouts;
        cmt::Pulser                             _lookoutsChanged;

        std::map<Mapping *, cmt::task::Owner>   _workers;
    };

    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    template <class L>
    L* Mapper::add(auto&&... args)
    {
        std::unique_ptr<L> l = std::make_unique<L>(this, std::forward<decltype(args)>(args)...);
        L* raw = l.get();
        _lookouts.emplace(std::move(l));
        return raw;
    }
}
