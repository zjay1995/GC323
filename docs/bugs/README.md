# Bug lists

One file per release: `docs/bugs/<version>.md`. It lists every issue the
release fixed and every issue known to be open in it, each with a
severity and the models it affects.

Two things it answers, which nothing in this project could answer before:

- A customer on GC323 2.5.0 reports something. Is it known? Open
  `2.5.0.md`.
- We are about to ship 2.5.1 to a GC301 site. What changed for the 301
  specifically? Open `2.5.1.md` and read the Models column.

## Severity

| Severity | Meaning |
| -------- | ------- |
| **critical** | Wrong measurements reported as good, or an unsafe hardware state (heater, valve, lamp). Ship a hotfix. |
| **major** | The instrument cannot do part of its job: a run fails, calibration fails, data is lost, it will not connect. |
| **minor** | Wrong or awkward behaviour with a workaround. Display and printout problems. |
| **cosmetic** | Wording, layout, spelling. |

## Models

List the models affected, or `all`. "Affected" means the code path is
actually reachable in that model's config - a fix inside `#if FID()`
does not affect a product built with `FID() 0`. Check the config before
writing `all`.

## Rules

- Every fix in a release appears here, and every entry names an issue.
  No issue, no entry; open the issue first.
- A commit that fixes something says so: `... (#123)`.
- Do not edit a released file afterwards. If something was wrong or newly
  discovered, it belongs in the next release's file under "Known open".
