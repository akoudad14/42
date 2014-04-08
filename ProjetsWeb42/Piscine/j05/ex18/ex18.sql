SELECT nom FROM distrib
WHERE id_distrib IN(42, 62, 63, 64, 65, 66, 67, 68, 69, 71, 88, 89, 90)
UNION
SELECT nom FROM distrib
WHERE nom LIKE "%y%y%"
LIMIT 2, 5;