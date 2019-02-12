CREATE TABLE IF NOT EXISTS Animals(
	shelterID INTEGER NOT NULL,
	animalName text NOT NULL,
	animalSpecies text NOT NULL,
	animalBreed text NOT NULL,
	animalAge INTEGER NOT NULL,
	animalSex char NOT NULL,
	animalTrainingLevel INTEGER NOT NULL,
	animalAffinityForPeople INTEGER NOT NULL,
	animalAffinityForChildren INTEGER NOT NULL,
	animalAffinityForAnimals INTEGER NOT NULL,
	animalApproachability INTEGER NOT NULL,
	animalTimeCommitment INTEGER NOT NULL,
	animalDietNeeds text NOT NULL,
	animalMobilityNeeds text NOT NULL,
	animalDisablityNeeds text NOT NULL,
	animalAbuseHistory text NOT NULL,
	animalBiography text NOT NULL,
	FOREIGN KEY(animalSpecies, animalBreed) REFERENCES AnimalsBreedsRelationship(speciesName, breedName)
	PRIMARY KEY(shelterID)
);

CREATE TABLE IF NOT EXISTS Species(
	speciesName text NOT NULL,
	primary key(speciesName)
);

CREATE TABLE IF NOT EXISTS Breeds(
	speciesName text NOT NULL,
	breedName text NOT NULL,
	FOREIGN KEY(speciesName) REFERENCES Species(speciesName),
	PRIMARY KEY(speciesName, breedName)
);

CREATE TABLE IF NOT EXISTS AnimalsBreedsRelationship(
	shelterID INTEGER NOT NULL,
	breedName text NOT NULL,
	FOREIGN KEY(shelterID) REFERENCES Animals(shelterID),
	FOREIGN KEY(breedName) REFERENCES Breeds(breedName)
);
/*
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
INSERT OR REPLACE INTO
	Species(
		speciesName
	)VALUES(
		"Cat"
	);

INSERT OR REPLACE INTO
	Breeds(
		speciesName,
		breedName
	)VALUES(
		"Cat",
		"Tabby"
	);

INSERT OR REPLACE INTO
	Animals(
		shelterID,
		animalName,
		animalSpecies,
		animalBreed,
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
	)VALUES(
		0,
		"Linus",
		"Cat",
		"Tabby",
		3,
		'M',
		1,
		2,
		2,
		2,
		2,
		1,
		"",
		"",
		"",
		"",
		"Loves people"
	);
INSERT OR REPLACE INTO
	Animals(
		shelterID,
		animalName,
		animalSpecies,
		animalBreed,
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
	)VALUES(
		1,
		"Quinn",
		"Cat",
		"Tabby",
		3,
		'M',
		1,
		1,
		1,
		2,
		0,
		1,
		"",
		"",
		"",
		"",
		"Has to get used to you"
	);

INSERT OR REPLACE INTO
	Animals(
		shelterID,
		animalName,
		animalSpecies,
		animalBreed,
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
	)VALUES(
		2,
		"Amy",
		"Dog",
		"Bishon/Poodle",
		10,
		'F',
		2,
		0,
		1,
		1,
		2,
		0,
		"",
		"",
		"",
		"",
		"Borks at everyone"
	);

INSERT OR REPLACE INTO
	Animals(
		shelterID,
		animalName,
		animalSpecies,
		animalBreed,
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
	)VALUES(
		3,
		"Tanner",
		"Dog",
		"Chihuahua",
		3,
		'M',
		0,
		0,
		2,
		0,
		1,
		1,
		"",
		"",
		"",
		"",
		"Doesnt like anybody at all"
	);

INSERT OR REPLACE INTO
	Animals(
		shelterID,
		animalName,
		animalSpecies,
		animalBreed,
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
	)VALUES(
		4,
		"Jake",
		"Dog",
		"Beagle",
		14,
		'M',
		1,
		1,
		2,
		2,
		1,
		0,
		"",
		"",
		"",
		"",
		"likes everbody; ded"
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
