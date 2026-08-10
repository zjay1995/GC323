# Changelog

Newest first. Each release links to its bug list in `docs/bugs/`.
Versions come from `VERSION`; see [docs/RELEASING.md](docs/RELEASING.md).

## 2.5.0 - unreleased

Bug list: [docs/bugs/2.5.0.md](docs/bugs/2.5.0.md)
Products: gc323 2.5.0, gc301 2.5.0, m30 0.1.0 (not shippable)

No functional change to measurement, control or reporting. This release
is the point where a build can be reproduced from the repository.

**Product names and versions**

- One name per product: `gc323`, `gc301`, `m30`. The name is the config
  file name, the `VERSION` key and the build directory name.
- Versions live in `VERSION`, one line per product, and are compiled in
  from there. `ABOUT.CPP` no longer contains a version literal - it
  carried the current one plus twenty-three commented-out predecessors.
- The About box shows the model and the version of the build. A customer
  can read out `GC323  2.5.0` and it cannot be wrong.
- `DEVICE_NAME` comes from the model config instead of a chain of
  `#elif`s on flags like `GC326()` in `MAINWIND.H`.
- Copyright updated to 1999-2026.

**Build**

- `config/gc323.h`, `config/gc301.h`, `config/m30.h` hold every
  compile-time switch for a product. `src/INTERNAL.H` keeps only what is
  derived from them (board numbers, `_NOCOMM`, `MAX_POINTS`).
- `tools/build.bat <model>` generates `src/MODELCFG.H` and
  `src/VERSION.H`, cleans when the model or version changed, builds, and
  collects to `build/<model>-<version>/`. Nothing is edited before a
  build.
- Built EXEs keep the name `WPEAK.EXE`. Renaming them is how `JW_V16.ini`,
  `JW_20.ini` and `QAGC32~1.ini` each ended up with a different flow
  calibration - Windows names the settings file after the EXE.

**Repository**

- 110 files removed: 56 `.obj`, 8 EXEs, backups, five old copies of
  `ACQUIRE.CPP`, four superseded help files, IDE state, grep dumps.
  19 MB -> 2.9 MB. Full list and recovery instructions in
  [docs/CLEANUP-2026-08.md](docs/CLEANUP-2026-08.md).
- Sources moved from `gc323-2026-08-07/` to `src/`. The dated folder name
  was itself the naming problem.
- Added `docs/BRANCHING.md`, `docs/RELEASING.md`, `docs/ARCHIVE.md`,
  `docs/BUILDING.md`, `docs/bugs/`, and a `.gitignore` that keeps the
  removed categories out.

## 2.4.44 and earlier

No changelog was kept. The version history is the commented-out
`ABOUT_APP_NAME` lines that used to sit at the top of `ABOUT.CPP`; they
are in git history at commit `321c309` if anyone needs the dates:

```
2.4.44  2019-03-27  flow setting added
2.4.43  2018-07-16  desorb and FID temperatures separated from inj_det
2.4.42  2018-03-26  desorb wait time
2.4.41  2017-12-01  calresults[] values are double
2.4.40  2017-11-03  next point time separated from purge
2.4.39  2017-03-29  line temperature
2.4.38  2017-03-12  desorber time
2.4.37  2013-01-25  scaling peaks
2.4.36  2012-11-09  range_1
2.4.35  2012-09-07  oven door manual
2.4.34  2012-02-24  data to Excel
2.4.33  2010-12-16  quick scan
2.4.32  2010-06-20
2.4.31  2010-03-07
2.4.30  2009-03-25
2.4.29  2008-11-14
2.4.28  2007-04-16
2.4.26  2006-07-20
2.4.25  2005-09-18
2.4.24  2005-09-18
2.4.23  2004-09-20
2.4.22  2004
```

Those dates are when the line was edited, not when anything shipped, and
they say nothing about which models got which build.
