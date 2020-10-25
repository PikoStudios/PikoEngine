#pragma once

const char *pkGetCurrentOS()
{
  #if defined(_WIN32)
    return "WIN32";
  #elif defined(__linux__)
    return "LINUX";
  #elif defined(__APPLE__)
    return "DARWIN/MACOS";
  #elif defined(BSD)
    return "BSD";
  #elif defined(__QNX__)
    return "QNX";
  #endif
}