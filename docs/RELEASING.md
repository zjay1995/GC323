# Releasing

A release is a tag on `main` plus a changelog entry plus a bug list. If
any of the three is missing it is not a release, it is an EXE someone
emailed.

## Steps

1. **Pick the version.** Edit `VERSION` on `develop`. Patch for fixes,
   minor for new behaviour, major for anything that breaks existing
   methods, saved data or the instrument interface. Only the products
   actually being released get bumped.

2. **Write the bug list.** `docs/bugs/<version>.md`, from the template in
   `docs/bugs/TEMPLATE.md`. Every entry names the issue, the severity and
   the models affected. Every fix in the release must appear. If a fix has
   no issue, open one now - the issue is where "which models does this
   affect" gets recorded.

3. **Write the changelog entry.** `CHANGELOG.md`, newest at the top.

4. **Build every product being released** and check the About box:

   ```
   tools\build.bat gc323
   tools\build.bat gc301
   ```

   Read the About box on each. It must say the right model and the
   version you just set. If it does not, the build picked up a stale
   generated header - delete `src\MODELCFG.H`, `src\VERSION.H` and
   `src\BUILD.STAMP` and build again.

5. **Test.** At minimum, on each product being released: it starts, it
   connects to the hardware, a run completes, a report prints, and the
   fixes in the bug list are actually fixed.

6. **Merge and tag.**

   ```
   git checkout main
   git merge --no-ff develop
   git tag -a v2.5.0 -m "Peak Works 2.5.0"
   git push origin main --tags
   git checkout develop
   git merge main
   ```

   One tag covers the release. Where products are on different versions,
   tag per product: `gc323-v2.5.0`.

7. **Archive the built EXEs.** See [ARCHIVE.md](ARCHIVE.md). They do not
   go in the repository.

## Rebuilding a shipped version

```
git checkout v2.5.0
tools\build.bat gc323
```

The config and the version are both in the tag, so the build is the same
one the customer has. This is the reason none of it is typed in at build
time.

## When a customer reports a problem

1. Ask them to read out line 5 of the About box: `GC323  2.5.0`.
2. `git checkout v2.5.0` for the tree they are running.
3. `docs/bugs/2.5.0.md` for what was known at the time.
4. Open an issue. Record the model and the version on it.
