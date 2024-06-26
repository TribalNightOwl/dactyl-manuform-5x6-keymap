/*
Copyright 2012 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#define USE_SERIAL

#define MASTER_LEFT
//#define MASTER_RIGHT

//#define EE_HANDS

#undef  TAPPING_TERM
#define TAPPING_TERM 200

#define TAPPING_TOGGLE 2

// #define IGNORE_MOD_TAP_INTERRUPT

#undef  ONESHOT_TAP_TOGGLE
#define ONESHOT_TAP_TOGGLE 2  /* Tapping this number of times holds the key until tapped this number of times again. */

#undef  ONESHOT_TIMEOUT
#define ONESHOT_TIMEOUT 5000  /* Time (in ms) before the one shot key is released */

#undef  DEBOUNCE
#define DEBOUNCE 2

#undef DEBOUNCE_DELAY
#define DEBOUNCE_DELAY 9
