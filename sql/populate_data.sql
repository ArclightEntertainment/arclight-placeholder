DROP TABLE IF EXISTS Animals;
CREATE TABLE IF NOT EXISTS Animals(
	animalID INTEGER PRIMARY KEY AUTOINCREMENT,
	animalName text NOT NULL,
	animalAge INTEGER NOT NULL,
	animalSex text NOT NULL,
	animalTrainingLevel INTEGER NOT NULL,
	animalAffinityForPeople INTEGER NOT NULL,
	animalAffinityForChildren INTEGER NOT NULL, 
	animalAffinityForAnimals INTEGER NOT NULL,
	animalApproachability INTEGER NOT NULL,
	animalTimeCommitment INTEGER NOT NULL,
	animalDietNeeds text,
	animalMobilityNeeds text,
	animalDisablityNeeds text,
	animalAbuseHistory text,
	animalBiography text
);
/*
CREATE TABLE IF NOT EXISTS Species(
	speciesName
);
*/
/*
DROP TABLE IF EXISTS Clients;
CREATE TABLE IF NOT EXISTS Clients(
	clientID INTEGER NOT NULL,
	clientFName text NOT NULL,
	clientLName text NOT NULL,
	clientPrefTitle text,
	clientAge INTEGER NOT NULL,
	primary key(clientID)
);
*/
begin transaction;

insert or replace into 
	Animals(
		animalName,
		animalAge,
		animalSex,
		animalTrainingLevel,
		animalAffinityForPeople,
		animalAffinityForChildren,
		animalAffinityForAnimals,
		animalApproachability,
		animalTimeCommitment,
		animalDietNeeds,
		animalMobilityNeeds,
		animalDisablityNeeds,
		animalAbuseHistory,
		animalBiography
	)values(
		"Linus",
		3,
		"M",
		1,
		2,
		2,
		2,
		2,
		1,
		"",
		NULL,
		"",
		NULL,
		"Loves people"
	);
insert or replace into 
	Animals(
		animalName,
		animalAge,
		animalSex,
		animalTrainingLevel,
		animalAffinityForPeople,
		animalAffinityForChildren,
		animalAffinityForAnimals,
		animalApproachability,
		animalTimeCommitment,
		animalDietNeeds,
		animalMobilityNeeds,
		animalDisablityNeeds,
		animalAbuseHistory,
		animalBiography
	)values(
		"Quinn",
		3,
		"M",
		1,
		1,
		1,
		2,
		0,
		1,
		"",
		"",
		NULL,
		NULL,
		"Has to get used to you"
	);
/*

insert or replace into Animals(animalName, animalAge, animalSex, animalSpecies, animalBreed)
	values(
		"Amy",
		10,
		"F",
		"Dog",
		"Bichon Frise/Poodle"
	);
*/
end transaction;
