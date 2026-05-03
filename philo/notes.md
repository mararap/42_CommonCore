# Notes

This notes refer to

```git
commit 269c888f86f038e89a92dba4006f876631e4f73c (HEAD -> comments_rene, main01)
| Author: marapovi <marapovi@student.42vienna.com>
| Date:   Sun May 3 18:54:46 2026 +0200
| 
|     cleanup
```

## Rückfragen

* Jeder Philo hat seine eigenen privaten Startzeitpunkt,
  um eine Mahlzeit zu beginnen. 
  Ist dies so gewünscht? (Philo 0, 2, 4 sollen leicht abweichende
  Startzeiten haben?)

## Feedback

### Minor issues

* in `ph_eat`: The counter increasement
  `p->meal_count++;`
  is done always, i.e. also when the optional last command line parameter is not specified.
  While practically this should cause no issues, it should be avoided for principal reasons: If the simulations would run for an extremly long time then this **signed** integer would
  finally overflow, resulting in undefined behaviour.

* Use of `printf` might mess up the output

### Likely major issues

* The used time checks `ph_get_time_us() < end`
  are *loosing precision* by going from microseconds to milliseconds;3 599 200 200


999 us  --> 0 ms

1001 us --> 1 ms

