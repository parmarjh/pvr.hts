#pragma once

/*
 *      Copyright (C) 2017 Team Kodi
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
 *  along with XBMC; see the file COPYING.  If not, write to
 *  the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.
 *  http://www.gnu.org/copyleft/gpl.html
 *
 */

#include <string>

#include "../../client.h"

namespace tvheadend
{
  namespace utilities
  {
    /**
     * Encapsulates an localized string.
     */
    class CLocalizedString
    {
    public:
      explicit CLocalizedString(int stringId)
      : m_localizedString(XBMC->GetLocalizedString(stringId))
      {
      }

      ~CLocalizedString()
      {
        XBMC->FreeString(m_localizedString);
      }

      std::string Get() const
      {
        return m_localizedString ? std::string(m_localizedString) : std::string();
      }
      
    private:
      CLocalizedString() = delete;
      CLocalizedString(const CLocalizedString&) = delete;
      CLocalizedString &operator =(const CLocalizedString&) = delete;

      char* m_localizedString;
    };
  }
}