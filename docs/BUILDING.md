# Building

## The short version

```
tools\build.bat gc323
```

That is the whole procedure. There is nothing to edit first.

## What it does

1. Reads `config\gc323.h` and copies it to `src\MODELCFG.H`.
2. Reads the `gc323=` line out of `VERSION` and writes `src\VERSION.H`.
3. Cleans the objects if the model or version changed since the last build.
4. Runs the Borland build.
5. Copies the result to `build\gc323-2.5.0\`.

`src\MODELCFG.H` and `src\VERSION.H` are generated. They are in
`.gitignore`, they must not be committed, and editing them is pointless -
the next build overwrites both.

Requirements: `cmd.exe` (Windows NT/2000/XP or later - not the Windows 9x
`command.com`), and a Borland C++ install. The script assumes
`D:\BORLANDC`; pass a different root as the second argument:

```
tools\build.bat gc323 C:\BORLANDC
```

If that install has `PRJ2MAK.EXE`, the build runs unattended. If it does
not, the script opens `WPEAK.PRJ` in the IDE, you press F9, and when you
close the IDE the script collects the output. Either way the generated
headers are already in place, so the IDE build is configured correctly
too.

## One name per product

Each product is one file in `config\`. The file name is the model name
used everywhere else: on the command line, in `VERSION`, in
`docs\bugs\`, and in the build directory.

The two lines at the top of each config are what a customer sees:

```c
#define MODEL_CODE        "GC323"
#define MODEL_DEVICE_NAME "GC323 Gas Chromatograph"
```

`MODEL_DEVICE_NAME` used to be picked by a chain of `#elif`s in
`src\MAINWIND.H` keyed off flags like `GC326()`, which is why working out
what a given EXE actually was meant reading the source. `MAINWIND.H` now
just says `#define DEVICE_NAME MODEL_DEVICE_NAME`.

The old flags (`GC326()`, `GC321()`, `GC501()` ...) still exist because
the code reads them in hundreds of places. They select behaviour. They no
longer select the name.

## The version comes from `VERSION`

`VERSION` holds one line per product:

```
gc323=2.5.0
gc301=2.5.0
m30=0.1.0
```

`build.bat` turns the line for the model being built into `src\VERSION.H`:

```c
#define PW_VERSION_MAJOR 2
#define PW_VERSION_MINOR 5
#define PW_VERSION_PATCH 0
#define PW_VERSION_STR   "2.5.0"
```

and `src\ABOUT.CPP` uses `PW_VERSION_STR`. Nothing else in the tree may
contain a version number. `ABOUT.CPP` used to carry the current version
as a literal with twenty-three previous ones commented out above it; that
history is in `git log VERSION` and in `CHANGELOG.md` now.

Bump **patch** for a bug fix, **minor** for new behaviour, **major** for a
change that breaks methods, saved data or the instrument interface.

## What the About box shows

```
GC323 Gas Chromatograph
 S/N ...

Peak Works for Windows
GC323  2.5.0
built Aug 10 2026

PID Analyzers (HNU Technology)
1999-2026
 Warning: Only exit PW via File/Exit
```

Line 5 is the one to ask a customer to read out: model and version, from
the config file and `VERSION`, so it cannot disagree with what was built.
The build date is `__DATE__`, filled in by the compiler.

That block is exactly ten lines and has to stay that way. The control it
goes into (`ID_ABOUTDIALOG` / `IDD_ABOUT_APP_NAME` in `WPEAK.RC`) is 80
dialog units tall in an 8 pt font. An eleventh line is clipped silently.

The "Features included" box below it is unchanged: it still lists the
features the switches turned on, and still ends with the Program Code -
the hex encoding of those switches. The bit numbers in the config files
are that encoding, so do not renumber them.

## Adding a product

1. Copy the closest existing `config\<model>.h` and edit the identity and
   the switches. Every switch must be defined in every model file.
2. Add a `<model>=0.1.0` line to `VERSION`.
3. Add `docs\bugs\<model>-0.1.0.md` at release time.
4. `tools\build.bat <model>`.

If the new product needs behaviour no existing switch covers, add a new
switch and use it the way `GC326()` is used. Do not overload another
model's flag - that is how `GC326()` came to mean "GC323".
