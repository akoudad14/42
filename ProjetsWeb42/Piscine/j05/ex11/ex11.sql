SELECT UCASE(fiche_personne.nom) AS NOM, prenom, prix
FROM fiche_personne
INNER JOIN membre ON membre.id_fiche_perso=fiche_personne.id_perso
INNER JOIN abonnement ON membre.id_abo = abonnement.id_abo
WHERE abonnement.prix > 42
ORDER BY fiche_personne.nom, prenom;