/*
 *      Copyright (C) 2018 Team Kodi
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
 *  along with Kodi; see the file COPYING.  If not, see
 *  <http://www.gnu.org/licenses/>.
 *
 */

#include "MediaRouter.h"

#include "MediaRouteSelector.h"
#include "Context.h"

#include "jutils-details.hpp"

using namespace jni;

/*************/

void CJNIMediaRouter::addCallback(const CJNIMediaRouteSelector &selector, const jni::jhobject &callback)
{
  call_method<void>(m_object,
    "addCallback", "(Landroid/support/v7/media/MediaRouteSelector;Landroid/support/v7/media/MediaRouter$Callback;)V",
    selector.get_raw(), callback);
}

CJNIMediaRouter CJNIMediaRouter::getInstance(const CJNIContext &context)
{
  return call_static_method<jhobject>("android/support/v7/media/MediaRouter",
    "getInstance", "(Ljava/lang/String;)Landroid/content/Context;", context.get_raw());
}
