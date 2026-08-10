# Peak Works

Instrument control and chromatography software for PID Analyzers (HNU
Technology) gas chromatographs. 16-bit Windows, Borland C++ with OWL.

One code base, one build per product:

| Product | Config            | Version source     |
| ------- | ----------------- | ------------------ |
| GC323   | `config/gc323.h`  | `VERSION` (`gc323`) |
| GC301   | `config/gc301.h`  | `VERSION` (`gc301`) |
| M30     | `config/m30.h`    | `VERSION` (`m30`)   |

## Build

```
tools\build.bat gc323
```

Output lands in `build\gc323-2.5.0\WPEAK.EXE`, and the About box in that
build reads `GC323  2.5.0`. Nothing is edited by hand first. See
[docs/BUILDING.md](docs/BUILDING.md).

## Layout

```
VERSION            one version number per product - the only place they live
config/            one file per product; all the compile-time switches
src/               the source, flat, as the Borland project expects it
tools/build.bat    pick a model, generate the headers, build, collect
docs/              how we build, branch, release and archive
docs/bugs/         one bug list per release
archive/           read-only; see docs/ARCHIVE.md
CHANGELOG.md       what shipped, when, and what it fixed
```

## Working on it

- Work on `develop`, off a short-lived branch, and get it reviewed.
  Releases are tagged off `main`. [docs/BRANCHING.md](docs/BRANCHING.md)
- Every fix references an issue, and every release lists what it fixed.
  [docs/RELEASING.md](docs/RELEASING.md), [docs/bugs/](docs/bugs/)
- Old versions are commits and tags, not copied folders or `.BAK` files.
  [docs/ARCHIVE.md](docs/ARCHIVE.md)

## Where the old tree went

This repository used to hold a dated snapshot folder plus a 5 MB zip of
the same thing: 314 files, 19 MB, including 56 `.obj` files, eight EXEs,
five old copies of `ACQUIRE.CPP` and four superseded help files.
What is left is 204 files and 2.9 MB of actual sources and resources.
[docs/CLEANUP-2026-08.md](docs/CLEANUP-2026-08.md) lists every file that
was removed and why, and how to get any of them back.
