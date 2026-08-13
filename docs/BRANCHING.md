# Branching

We branch in git. We do not branch by copying folders.

`jw_v67`, `jw_v81` and `301_20250218` were branches - they just had no
history, no diff, no review and no way to merge. Anything you would have
done by copying the folder, do with a branch instead.

## The two long-lived branches

**`main`** is what is installed on customer instruments. Only release
merges land here, and every commit on `main` is tagged. If a customer
reports a problem with 2.5.0, `git checkout v2.5.0` gives you the exact
tree it was built from.

**`develop`** is the integration branch. This is the default branch and
where day-to-day work lands. It should build for every model at all
times.

## Working

```
git checkout develop
git pull
git checkout -b fix/123-oven-door-timeout
```

Name the branch after the issue: `fix/<issue>-<words>`,
`feature/<issue>-<words>`. Keep it small and keep it short-lived - a
branch that lives for weeks is a folder copy with extra steps.

Commit messages reference the issue and say what changed and why:

```
Close the oven door relay before the fan starts (#123)

The door and the fan were driven in the same pass, so on the GC323 the
door could still be moving when the fan came on and the oven overshot.
```

Then open a pull request into `develop`. **One other person reads it
before it merges.** That is the change in habit, and it is the point of
all of this: nothing reaches an instrument that only one person has seen.

A review is looking for: does it build for every model in `config\`; does
it touch a shared file in a way that changes another model's behaviour;
is there an issue; does the issue say which models are affected.

## Releasing

`develop` -> `main`, tagged. See [RELEASING.md](RELEASING.md).

## Hotfixes

If something is broken in the field and `develop` is not ready to ship,
branch from the tag, not from `develop`:

```
git checkout -b hotfix/2.5.1 v2.5.0
```

Fix it, bump the patch in `VERSION`, merge into `main`, tag, then merge
`main` back into `develop` so the fix is not lost.

## What not to do

- Do not copy a folder to make a variant. Branch.
- Do not keep an old version as `ACQUIRE.CPP.ok` next to the real one.
  Commit, and read it back with `git show`. See [ARCHIVE.md](ARCHIVE.md).
- Do not commit to `main` directly.
- Do not commit `src\MODELCFG.H` or `src\VERSION.H`; they are generated.
- Do not commit an EXE.
