# archive/

Built EXEs of tagged releases. Read-only: once a directory is written it
is never edited and never deleted.

The rule for what belongs here, and what to do with the EXEs currently
scattered across the shared drive, is in
[../docs/ARCHIVE.md](../docs/ARCHIVE.md).

## Layout

```
gc323-2.5.0/
  WPEAK.EXE
  WPEAK.HLP
  BUILD.TXT      written by tools\build.bat: model, version, config, date
  SHA256.txt
```

One directory per released product version, named `<model>-<version>`.
Nothing else.

## Location

The binaries themselves are **not** in git - EXEs are in `.gitignore`.
This directory documents the convention; the files live on the shared
drive.

> **TODO:** record the shared-drive path here, e.g.
> `\\piRshared\software\peakworks\archive\`. Until this line is filled
> in, the archive rule has nowhere to point and the EXEs will keep piling
> up next to the sources.

## Adding a release

```
tools\build.bat gc323
```

then copy `build\gc323-2.5.0\` to the archive location, add a
`SHA256.txt`, and make the directory read-only. Only do this for a
version that has a tag on `main`.
