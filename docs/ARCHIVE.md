# Archive

## The rule

**Old versions of source do not live in the working tree.** A version
worth keeping is a commit; a release worth keeping is a tag. Nothing in
`src/` is ever a copy of something else in `src/`.

That means no `ACQUIRE.BAK`, no `ACQUIRE.CPP.ok`, no `ACQUIRE.CPPorig`,
no `HELP_112808.RTF`, no `keep/` folder, no `301_20250218/`. `.gitignore`
blocks the common suffixes so they cannot come back by accident.

To read an old version, ask git:

```
git log --oneline -- src/ACQUIRE.CPP     # every change to the file
git show v2.5.0:src/ACQUIRE.CPP          # the file as it shipped in 2.5.0
git diff v2.4.44 v2.5.0 -- src/          # what changed between releases
```

## What `archive/` is for

`archive/` holds exactly one thing: **built EXEs of tagged releases**,
because those cannot be regenerated once the Borland toolchain is gone
from the last machine that has it.

```
archive/
  gc323-2.5.0/
    WPEAK.EXE
    WPEAK.HLP
    BUILD.TXT      model, version, config, build date
    SHA256.txt
```

One directory per released product version, named `<model>-<version>` -
the same name `build.bat` produces. Nothing else goes in.

`archive/` is **read-only**. Once a directory is written it is never
edited and never deleted. If a build was wrong, release another version;
do not overwrite the bad one, because it is on a customer's instrument.

It is not stored in git - EXEs are in `.gitignore` and this repository
does not need to carry 700 KB per release forever. It lives on the shared
drive at the location recorded in `archive/README.md`, and this file
describes what belongs in it.

## What does not go in `archive/`

- Source. That is what tags are for.
- Anything untagged: dev builds, "QA" builds, anything for one customer.
  If it went to a customer it needed a version; if it did not, it is not
  worth keeping.
- Anything without a `BUILD.TXT` saying which model and version it is.
  This is the rule that would have prevented `NOfanNOdoor.exe`,
  `QA.gc323.MAYBE.QA.bradshaw.051520.QA.EXE` and `jw_v21.EXE`.

## Retiring the current mess

The 471 EXEs and 285 backup files scattered across the old folders are
not covered by any of the above; nothing about them is known. Suggested
one-off pass, oldest work first:

1. For any EXE that can be matched to a customer site, move it to
   `archive/unverified/<name>/` with a note saying where it came from.
   Do not invent a version number for it.
2. For the folder copies (`jw_v67`, `jw_v81`, `301_20250218`): if the
   sources differ from anything already in git history and the difference
   matters, commit them on a branch named after the folder so the diff is
   visible. Otherwise leave them where they are.
3. Delete nothing until the above is done and someone has agreed to it.
4. Then the shared drive holds one directory per released version and
   nothing else, and this rule applies from then on.
