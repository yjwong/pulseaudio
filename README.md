# PulseAudio PPA for Ubuntu 20.04

This PPA contains PulseAudio packages, incorporating mSBC/WBS and fixes low
volume on some Bluetooth headsets.

The following merge requests are included on top of the 14.2 release, along with
their merge dates for easy reference:

- [Messaging API V2](https://gitlab.freedesktop.org/pulseaudio/pulseaudio/-/merge_requests/51) (merged Dec 3, 2020 10:48pm GMT+0800)
- [core, modules: Remove useless EINTR tests](https://gitlab.freedesktop.org/pulseaudio/pulseaudio/-/merge_requests/238) (merged Dec 9, 2020 6:33pm GMT+0800)
- [Add support for bluetooth A2DP codecs and codec switching](https://gitlab.freedesktop.org/pulseaudio/pulseaudio/-/merge_requests/440) (merged Jan 19, 2021 11:33pm GMT+0800)
- [bluetooth: Check support for encoding and decoding separately](https://gitlab.freedesktop.org/pulseaudio/pulseaudio/-/merge_requests/479) (merged Jan 21, 2021 11:05pm GMT+0800)
- [bluetooth: allow increasing output bitrate](https://gitlab.freedesktop.org/pulseaudio/pulseaudio/-/merge_requests/481) (merged Jan 21, 2021 11:15pm GMT+0800)
- [bluetooth: allow increasing output bitrate for SBC codec](https://gitlab.freedesktop.org/pulseaudio/pulseaudio/-/merge_requests/474) (merged Jan 21, 2021 11:21pm GMT+0800)
- [bluetooth: pass output_rate_refresh_interval_ms module parameter](https://gitlab.freedesktop.org/pulseaudio/pulseaudio/-/merge_requests/488) (merged Jan 26, 2021 11:40pm GMT+0800)
- [bluetooth: a2dp dual channel SBC XQ codec configurations](https://gitlab.freedesktop.org/pulseaudio/pulseaudio/-/merge_requests/476) (merged Feb 2, 2021 1:18am GMT+0800)
- [use bluetooth HFP in pulseaudio native backend when available](https://gitlab.freedesktop.org/pulseaudio/pulseaudio/-/merge_requests/491) (merged Feb 23, 2021 9:20pm GMT+0800)
- [bluetooth: check if target codec is available on the system](https://gitlab.freedesktop.org/pulseaudio/pulseaudio/-/merge_requests/518) (merged Mar 4, 2021 6:42am GMT+0800)
- [bluetooth: correct rfcomm command and reply formatting](https://gitlab.freedesktop.org/pulseaudio/pulseaudio/-/merge_requests/520) (merged Mar 6, 2021 6:34am GMT+0800)
- [bluetooth: Perform software attenuation until HF/HS reports gain control](https://gitlab.freedesktop.org/pulseaudio/pulseaudio/-/merge_requests/521) (merged Mar 16, 2021 6:04pm GMT+0800)
- [bluetooth: Set up hardware gain control if init volume is received late](https://gitlab.freedesktop.org/pulseaudio/pulseaudio/-/merge_requests/528) (merged Mar 18, 2021 6:26am GMT+0800)
- [bluetooth: Only use hardware volume callbacks for peer attenuation (hsp/hfp)](https://gitlab.freedesktop.org/pulseaudio/pulseaudio/-/merge_requests/519) (merged Mar 27, 2021 5:17am GMT+0800)
- [messaging api: use JSON instead of custom format](https://gitlab.freedesktop.org/pulseaudio/pulseaudio/-/merge_requests/525) (merged Mar 27, 2021 7:21pm GMT+0800)
- [bluetooth: WBS for native backend](https://gitlab.freedesktop.org/pulseaudio/pulseaudio/-/merge_requests/507) (merged Apr 5, 2021 11:52pm GMT+0800)

Some of these patches are technically not required, but were included to avoid
needing to resolve complicated merge conflicts.

## Why?

I was having trouble with my [Grado GW100](https://gradolabs.com/headphones/wireless/item/74-gw100),
where the microphone volume was too low for the other party.

An alternate solution was to replace PulseAudio with PipeWire entirely, but the
official PipeWire package in Ubuntu 20.04 LTS is too old and I didn't want to go
through the hassle of packaging a recent release.

## Installation

**Important Note**: This may require a recent kernel (I use 5.12.5) for mSBC to
work properly. See the comments in this [linked issue](https://gitlab.freedesktop.org/pulseaudio/pulseaudio/-/merge_requests/507).

To add this PPA to your system, run the following:

```shell
curl -s --compressed "https://yjwong.github.io/pulseaudio/key.gpg" | sudo apt-key add -
sudo curl -s --compressed -o /etc/apt/sources.list.d/pulseaudio.list "https://yjwong.github.io/pulseaudio/pulseaudio.list"
sudo apt update
sudo apt upgrade
```

After installation, you will also need to restart PulseAudio for the changes to
take effect:

```shell
systemctl --user daemon-reload
systemctl --user restart pulseaudio
```

## Building

Ensure you have the requisite build dependencies installed on your system.

Then, check out the `packaged/14.2.99` branch, then run:

```shell
git archive --format=tar.gz -o ../pulseaudio_14.2.99.orig.tar.gz --prefix=pulseaudio-14.2.99/ upstream/14.2.99
dpkg-buildpackage -uc -us
```

Built packages will be found in the parent directory.

## References

- [Hosting your own PPA repository on GitHub](https://assafmo.github.io/2019/05/02/ppa-repo-hosted-on-github.html)
