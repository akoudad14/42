SELECT COUNT(date) AS films
FROM historique_membre
WHERE
(DATEDIFF("2006-10-30", date) <= 0 AND DATEDIFF("2007-07-27", date) >= 0)
OR
(DAY(date) = 24 AND MONTH(date) = 12);