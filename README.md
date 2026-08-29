# GC323 — Peak Works

Control and chromatogram software for the **GC323 Gas Chromatograph** (PID Analyzers / HNU Technology).

This is the official repository for the GC323 build.

Current release: **v70.28**, built 2026-08-25 → `GC323_v70.28.exe`

## Repository layout

| Path | What it is |
|---|---|
| `GC323_v70.28/` | Source for the current release. Build this. |
| `GC323_v70.28.exe` | The compiled release binary. |
| `BORLANDC/` | The Borland C++ toolchain used to build it. |
| `gc323-2026-08-07/` | Earlier source tree, kept for reference. Not the build tree. |
| `changelog.docx` | Change history, newest entry first. |

## Building

The toolchain is **Borland C++ 3.1** (1992), in `BORLANDC/`. The build recipe is
`GC323_v70.28/BC.BAT`:

```
subst s: D:\BORLANDC
path s:\bin;%path
set tmp=c:\temp
set temp=c:\temp
set LIB=
set INCLUDE=
bc.exe
```

Then open `WPEAK.PRJ` in the IDE and build. The output is `WPEAK.EXE`; rename it to
`GC323_v<version>.exe` when releasing.

Note that `BC.EXE`, `BCC.EXE`, `TLINK.EXE`, `BRCC.EXE` and `MAKE.EXE` are **DOS**
protected-mode programs (Borland's BOSS/DPMI extender), not Windows programs. They
need a DOS environment — a 32-bit Windows install, a VM, or DOSBox. otvdm will not
run them; it is a Win16 layer only. `BCW.EXE`, the Windows-hosted IDE, is Win16 and
does load under otvdm, but this copy of the toolchain is missing `BWCC.DLL` (only
`BWCC.H` and `BWCC.LIB` are present — the runtime DLL normally lives in the Windows
system directory and was never copied here), so it cannot start.

`WINSTUB.EXE` must stay in the source folder — `WPEAK.DEF` names it, and the link
fails without it.

### Building here with DOSBox-X

`Build GC323.cmd` opens the Borland IDE in DOSBox-X with the mounts `BC.BAT` expects:
`S:` = `BORLANDC`, `D:` = the source, `C:` = a scratch drive holding `C:\TEMP`. Config
is `_tools/dosbox-x/gc323.conf`. Verified 2026-08-25: the IDE starts, and
`bc.exe /b wpeak.prj` does drive a real batch build.

### ⚠ The source tree is incomplete — it cannot be built yet

The build gets going and then fails with **677 errors**. The cause is not the
toolchain or the emulator: **three in-house library folders are missing from this
repository** and from every other copy on the machine.

| Missing folder | `#include`s referencing it |
|---|---|
| `winlib\` | 74 |
| `wcpplib\` | 48 |
| `winutil\` | 47 |

Their compiled libraries are missing too — the project links `WINLIB.LIB`,
`WCPPLIB.LIB`, `WINUTIL.LIB`, `UTIL.LIB`, `PLIB.LIB`, `NLIB.LIB` and `WMATH.LIB`, and
none of them are anywhere in the repo, in `BORLANDC/`, or in any of the archived zips.
`BORLANDC/CRTL/WINLIB` is Borland's own directory and is unrelated.

These are shared PID Analyzer libraries that lived alongside the application source on
the original build PC. **Copy those three folders (and their `.LIB` files) from the
machine that produced `GC323_v70.28.exe` into this repo**, then the build should
complete — here or anywhere else.

## Which model a build is

The GC model is chosen by `#define`s in `INTERNAL.H`, **not** by folder or file name.
The GC323 configuration is:

```
GC326()  1      RAMPING()   1      PULSING_OVEN() 1
MANUAL_INJ() 1  OVEN_EQ_INJ() 0    POINTS()       1
```

To confirm a compiled EXE is really a 323, search its bytes for the device string —
a genuine 323 contains `GC323 Gas Chromatograph`, while a 301 build contains
`GC301c Process Gas Chromatograph`. Filenames have been wrong before; this string
has not.

## Operating notes

- **AutoZero time** is set from the **AutoZero Time** field in Method → Edit
  (the field that used to be labelled "Inject Time"). Range 0–30 seconds;
  0 keeps the historical fixed 5 s. The status line counts it down during a run.
- **Oven temperature** is capped at 275 °C by the Method dialog. Conditioning above
  that has to be done in an external oven.
- The program talks to Measurement Computing USB DAQ hardware through the Universal
  Library (`MyCBW.CPP`). Without that hardware attached it will report board errors.

## Running on 64-bit Windows

The application is a **16-bit Windows (NE) executable**, so 64-bit editions of Windows
cannot launch it directly — they have no NTVDM subsystem. It does run under
**otvdm (winevdm)**, which is kept in `_tools/otvdm/`.

**To run it:** double-click `Run GC323.cmd`.

Verified working on Windows 11 Home 64-bit, 2026-08-25. The program starts and reaches
its own hardware check, then reports `CBW32.dll not found` because the Measurement
Computing Universal Library is not installed on that PC. Both `CBW32.DLL` and
`CTL3DV2.DLL` are loaded at runtime with fallbacks rather than linked at load time, so
the program keeps going without them. That is enough to check the UI, the About box and
Method settings — it is **not** enough to run an instrument. For that, use a PC with the
MCC Universal Library installed and the DAQ hardware attached.

otvdm can also register itself to open 16-bit executables on double-click
(`_tools/otvdm/otvdm-v0.9.0/install.inf`), but that changes system file associations,
so it is left off by default.
