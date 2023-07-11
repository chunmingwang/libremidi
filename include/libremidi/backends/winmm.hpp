#pragma once
#include <libremidi/backends/winmm/midi_in.hpp>
#include <libremidi/backends/winmm/midi_out.hpp>
#include <libremidi/backends/winmm/observer.hpp>

// Default for Windows is to add an identifier to the port names; this
// flag can be defined (e.g. in your project file) to disable this behaviour.
// #define LIBREMIDI_DO_NOT_ENSURE_UNIQUE_PORTNAMES

//*********************************************************************//
//  API: Windows Multimedia Library (MM)
//*********************************************************************//

// API information deciphered from:
//  -
//  http://msdn.microsoft.com/library/default.asp?url=/library/en-us/multimed/htm/_win32_midi_reference.asp

// Thanks to Jean-Baptiste Berruchon for the sysex code.
namespace libremidi
{

struct winmm_backend
{
  using midi_in = midi_in_winmm;
  using midi_out = midi_out_winmm;
  using midi_observer = observer_winmm;
  static const constexpr auto API = libremidi::API::WINDOWS_MM;
  static const constexpr auto name = "winmm";
  static const constexpr auto display_name = "Windows Multimedia";
};
}
