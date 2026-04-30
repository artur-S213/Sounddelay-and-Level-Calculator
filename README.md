
<!-- <h1 style="display: flex; align-items: center; border-bottom: none;">
  <img src="icons/icon.png" width="120" style="margin-right: 10px; vertical-align: middle;">
  <span style="vertical-align: middle;">Sdalcal</span>
</h1>-->

<p align="center">
  <img src="icons/icon.png" width="128" alt="Sdalcal Logo">
</p>

<h1 align="center" style="font-size: 5em; border-bottom: none;">
  <strong>Sdalcal</strong>
</h1>

<!-- # Sounddelay-and-Level-Calculator -->

![Status: In Development](https://img.shields.io/badge/Status-in%20Development-orange)

Sdalcal stands for "Sounddelay-and-Level-Calculator" and calculates the sounddelay between two louspeaker positions with a given distance and the soundlevel for the second loudspeakers.

![App Preview](docs/app_preview.png)

Hint:

- Sound pressure level ≠ sound intensity level
- L2=L1-20*log(r1/r2)
- L2=L1-10*log(r1/r2)²

#### References

1. Sengpielaudio: <https://sengpielaudio.com/Rechner-SchallUndEntfernung.htm>

## Project Requirements

This Project was created with the Slint GUI Framework.
For this project you need:

- C++ compiler that supports (at least) C++20
- cmake version 3.21 or newer


Checkout the documentation of slint framework: \
https://docs.slint.dev/latest/docs/cpp/

#### Install Build Essentials

For Debian, Ubuntu, Mint:

```bash
# Install dependencies
sudo apt update && sudo apt install -y \
    build-essential \
    git \
    cmake \
    curl \
    pkg-config \
    libfontconfig1-dev \
    libx11-dev \
    libxkbcommon-dev \
    libgl1-mesa-dev \
    libegl1-mesa-dev \
    libwayland-dev

# Install Rust Toolchain
curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs | sh -s -- -y
```

For Fedora:

```bash
# Install dependencies
sudo dnf install -y \
    git \
    gcc-c++ \
    cmake \
    curl \
    pkg-config \
    fontconfig-devel \
    libX11-devel \
    libxkbcommon-devel \
    mesa-libGL-devel \
    mesa-libEGL-devel \
    wayland-devel

# Install Rust Toolchain
curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs | sh -s -- -y
```
