#pragma once
#include <libremidi/backends/winuwp/midi_in.hpp>
#include <libremidi/backends/winuwp/midi_observer.hpp>
#include <libremidi/backends/winuwp/midi_out.hpp>

namespace libremidi
{
struct winuwp_backend
{
  using midi_in = midi_in_winuwp;
  using midi_out = midi_out_winuwp;
  using midi_observer = observer_winuwp;
  static const constexpr auto API = libremidi::API::WINDOWS_UWP;
  static const constexpr auto name = "winuwp";
  static const constexpr auto display_name = "Windows UWP";
};
} // namespace libremidi
