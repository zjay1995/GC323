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

Open `GC323_v70.28/WPEAK.PRJ` in the Borland IDE (`BORLANDC/BIN`) and build. The
output is `WPEAK.EXE`; rename it to `GC323_v<version>.exe` when releasing.

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
