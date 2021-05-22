# PulseAudio PPA for Ubuntu 20.04

This PPA contains PulseAudio packages, incorporating mSBC/WBS and fixes low
volume on some Bluetooth headsets.

The following merge requests are included on top of the 14.2 release, along with
ther merge dates for easy reference:

```
https://gitlab.freedesktop.org/pulseaudio/pulseaudio/-/merge_requests/51 Dec 3
https://gitlab.freedesktop.org/pulseaudio/pulseaudio/-/merge_requests/238 Dec 9
https://gitlab.freedesktop.org/pulseaudio/pulseaudio/-/merge_requests/440 Jan 19
https://gitlab.freedesktop.org/pulseaudio/pulseaudio/-/merge_requests/479 Jan 21
https://gitlab.freedesktop.org/pulseaudio/pulseaudio/-/merge_requests/481 Jan 21
https://gitlab.freedesktop.org/pulseaudio/pulseaudio/-/merge_requests/474 Jan 21
https://gitlab.freedesktop.org/pulseaudio/pulseaudio/-/merge_requests/488 Jan 26
https://gitlab.freedesktop.org/pulseaudio/pulseaudio/-/merge_requests/476 Feb 2
https://gitlab.freedesktop.org/pulseaudio/pulseaudio/-/merge_requests/491 Feb 23
https://gitlab.freedesktop.org/pulseaudio/pulseaudio/-/merge_requests/518 Mar 4
https://gitlab.freedesktop.org/pulseaudio/pulseaudio/-/merge_requests/520 Mar 6
https://gitlab.freedesktop.org/pulseaudio/pulseaudio/-/merge_requests/521 Mar 16
https://gitlab.freedesktop.org/pulseaudio/pulseaudio/-/merge_requests/528 Mar 18
https://gitlab.freedesktop.org/pulseaudio/pulseaudio/-/merge_requests/519 Mar 27
https://gitlab.freedesktop.org/pulseaudio/pulseaudio/-/merge_requests/525 Mar 27
https://gitlab.freedesktop.org/pulseaudio/pulseaudio/-/merge_requests/507 Apr 5
```

## Installation

To add this PPA to your system, run the following:

```shell
curl -s --compressed "https://yjwong.github.io/pulseaudio/key.gpg" | sudo apt-key add -
sudo curl -s --compressed -o /etc/apt/sources.list.d/pulseaudio.list "https://yjwong.github.io/pulseaudio/pulseaudio.list"
sudo apt update
```

## Building

Ensure you have the requisite build dependencies installed on your system.

Then, check out the `packaged/14.2.99` branch, then run:

```
git archive --format=tar.gz -o ../pulseaudio_14.2.99.orig.tar.gz --prefix=pulseaudio-14.2.99/ upstream/14.2.99
dpkg-buildpackage -uc -us
```

Built packages will be found in the parent directory.
