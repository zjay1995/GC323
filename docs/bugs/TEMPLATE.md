# Bugs - <version>

Released: <YYYY-MM-DD>
Products: <gc323 2.5.0, gc301 2.5.0>

## Fixed

| Issue | Severity | Models | Summary |
| ----- | -------- | ------ | ------- |
| #123 | major | gc323 | Oven overshot when the door was still moving as the fan started. |
| #124 | minor | all | Shift report printed the previous day's date after midnight. |

## Known open

| Issue | Severity | Models | Summary | Workaround |
| ----- | -------- | ------ | ------- | ---------- |
| #131 | minor | gc301 | Flow reading flickers below 0.5 ml/min. | Reading is correct; ignore the flicker. |

## Notes

Anything a field engineer needs that does not fit the tables: a method
file that has to be re-saved, a calibration that has to be re-run, a
setting whose default changed.
