/*
 *      Copyright (C) 2016 Team Kodi
 *      http://kodi.tv
 *
 *  This Program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2, or (at your option)
 *  any later version.
 *
 *  This Program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with XBMC; see the file COPYING.  If not, see
 *  <http://www.gnu.org/licenses/>.
 *
 */
#pragma once

#include <memory>
#include <string>

namespace ADDON
{

  class CAddonInfo;
  typedef std::shared_ptr<CAddonInfo> AddonInfoPtr;
  
  struct AddonEvent
  {
    virtual ~AddonEvent() {};
  };

  namespace AddonEvents
  {
    struct Enabled : AddonEvent
    {
      const AddonInfoPtr addonInfo;
      Enabled(const AddonInfoPtr addonInfo) : addonInfo(std::move(addonInfo)) {}
    };

    struct Disabled : AddonEvent
    {
      const AddonInfoPtr addonInfo;
      Disabled(const AddonInfoPtr addonInfo) : addonInfo(std::move(addonInfo)) {}
    };

    struct MetadataChanged : AddonEvent
    {
      std::string id;
      MetadataChanged(std::string id) : id(std::move(id)) {}
    };

    struct InstalledChanged : AddonEvent {};
  };
};
