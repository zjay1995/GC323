# GC323 — Peak Works

Control and chromatogram software for the **GC323 Gas Chromatograph** (PID Analyzers / HNU Technology).

This is the official repository for the GC323 build.

Current release: **v2.4.45**, built 2026-08-25 → `GC323_v2.4.45_20260825.exe`

## Repository layout

| Path | What it is |
|---|---|
| `GC323_v2.4.45/` | Source for the current release. Build this. |
| `GC323_v2.4.45_20260825.exe` | The compiled release binary. |
| `BORLANDC/` | The Borland C++ toolchain used to build it. |
| `gc323-2026-08-07/` | Earlier source tree, kept for reference. Not the build tree. |
| `changelog.docx` | Change history, newest entry first. |

## Building

Open `GC323_v2.4.45/WPEAK.PRJ` in the Borland IDE (`BORLANDC/BIN`) and build. The
output is `WPEAK.EXE`; rename it to `GC323_v<version>_<YYYYMMDD>.exe` when releasing.

`WINSTUB.EXE` must stay in the source folder — `WPEAK.DEF` names it, and the link
fails without it. `WPEAK.RC` also pulls three bitmaps (`bkgr`, `statbar`, `statline`)
from a `winutil\` folder on the include path, not from the source folder.

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

The application is a **16-bit Windows (NE) executable**. 64-bit editions of Windows
have no NTVDM subsystem, so it cannot be launched directly on a 64-bit machine —
Windows reports it as an unsupported application. It needs either a 32-bit Windows
installation, a virtual machine, or a 16-bit compatibility layer.
