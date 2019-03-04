CREATE TABLE IF NOT EXISTS Animals(
	shelterID INTEGER NOT NULL,
	animalName text NOT NULL,
	animalSpecies text NOT NULL,
	animalBreed text NOT NULL,
	animalAge INTEGER NOT NULL,
	animalSex char NOT NULL,
	animalLevelOfCare INTEGER NOT NULL,
	animalEstimatedCostPerMonth INTEGER NOT NULL,
	animalTrainingLevel INTEGER NOT NULL,
	animalTrainabilityLevel INTEGER NOT NULL,
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

/* NO BOOLEANS, 0 is false, 1 is true*/
CREATE TABLE IF NOT EXISTS Clients(
	clientID INTEGER NOT NULL,
	clientFName text NOT NULL,
	clientLName text NOT NULL,
	clientPrefTitle text NOT NULL,
	clientPhoneNumber text NOT NULL,
	clientAge INTEGER NOT NULL,
	clientHasChildrenUnderTwelve INTEGER NOT NULL,
	clientHasPets INTEGER NOT NULL,
	clientLengthOfOwnershipExpectation INTEGER NOT NULL,
	clientMonthlyBudgetForAnimal INTEGER NOT NULL,
	clientAvailabilityPerDay INTEGER NOT NULL,
	clientLevelOfMobility INTEGER NOT NULL,
	clientLevelOfEnergy INTEGER NOT NULL,
	clientLevelOfPatience INTEGER NOT NULL,
	clientPreviousExperience INTEGER NOT NULL,
	clientPhysicalAffection INTEGER NOT NULL,
	primary key(clientID)
);

CREATE TABLE IF NOT EXISTS Address(
	addressClientID INTEGER NOT NULL,
	addressStreetLine1 text NOT NULL,
	addressStreetLine2 text NOT NULL,
	addressCity text NOT NULL,
	addressSubnationalDivision text NOT NULL,
	addressCountry text NOT NULL,
	addressPostalCode text NOT NULL,
	FOREIGN KEY(addressClientID) REFERENCES Clients(clientID),
	PRIMARY KEY(addressClientID)
);

begin transaction;

INSERT OR REPLACE INTO Clients(
		clientID,
		clientFName,
		clientLName,
		clientPrefTitle,
		clientPhoneNumber,
		clientAge,
		clientHasChildrenUnderTwelve,
		clientHasPets,
		clientLengthOfOwnershipExpectation,
		clientMonthlyBudgetForAnimal,
		clientAvailabilityPerDay,
		clientLevelOfMobility,
		clientLevelOfEnergy,
		clientLevelOfPatience,
		clientPreviousExperience,
		clientPhysicalAffection
	)VALUES(
		0,
		"Brian",
		"LeBlanc",
		"Mr.",
		"6131234567",
		20,
		0,
		1,
		5,
		200,
		150,
		4,
		4,
		2,
		3,
		3
);

INSERT OR REPLACE INTO Address(
		addressClientID,
		addressStreetLine1,
		addressStreetLine2,
		addressCity,
		addressSubnationalDivision,
		addressCountry,
		addressPostalCode
	)VALUES(
		0,
		"123 Main Street",
		"",
		"Ottawa",
		"Ontario",
		"Canada",
		"A0A1B1"
);

INSERT OR REPLACE INTO Clients(
		clientID,
		clientFName,
		clientLName,
		clientPrefTitle,
		clientPhoneNumber,
		clientAge,
		clientHasChildrenUnderTwelve,
		clientHasPets,
		clientLengthOfOwnershipExpectation,
		clientMonthlyBudgetForAnimal,
		clientAvailabilityPerDay,
		clientLevelOfMobility,
		clientLevelOfEnergy,
		clientLevelOfPatience,
		clientPreviousExperience,
		clientPhysicalAffection
	)VALUES(
		1,
		"Brian",
		"Grickites",
		"Mr.",
		"6131112222",
		23,
		0,
		1,
		10,
		250,
		90,
		1,
		2,
		0,
		4,
		2
);

INSERT OR REPLACE INTO Address(
		addressClientID,
		addressStreetLine1,
		addressStreetLine2,
		addressCity,
		addressSubnationalDivision,
		addressCountry,
		addressPostalCode
	)VALUES(
		1,
		"321 Nighthawk Avenue",
		"",
		"Ottawa",
		"Ontario",
		"Canada",
		"C2C0A0"
);

INSERT OR REPLACE INTO Clients(
		clientID,
		clientFName,
		clientLName,
		clientPrefTitle,
		clientPhoneNumber,
		clientAge,
		clientHasChildrenUnderTwelve,
		clientHasPets,
		clientLengthOfOwnershipExpectation,
		clientMonthlyBudgetForAnimal,
		clientAvailabilityPerDay,
		clientLevelOfMobility,
		clientLevelOfEnergy,
		clientLevelOfPatience,
		clientPreviousExperience,
		clientPhysicalAffection
	)VALUES(
		2,
		"Shalin",
		"Lathigra",
		"Mrs.",
		"6139991234",
		17,
		0,
		0,
		2,
		75,
		45,
		2,
		0,
		4,
		2,
		0
);

INSERT OR REPLACE INTO Address(
		addressClientID,
		addressStreetLine1,
		addressStreetLine2,
		addressCity,
		addressSubnationalDivision,
		addressCountry,
		addressPostalCode
	)VALUES(
		2,
		"1888 Long Street",
		"Room Number 144",
		"Ottawa",
		"Ontario",
		"Canada",
		"N6M0L2"
);

INSERT OR REPLACE INTO Clients(
		clientID,
		clientFName,
		clientLName,
		clientPrefTitle,
		clientPhoneNumber,
		clientAge,
		clientHasChildrenUnderTwelve,
		clientHasPets,
		clientLengthOfOwnershipExpectation,
		clientMonthlyBudgetForAnimal,
		clientAvailabilityPerDay,
		clientLevelOfMobility,
		clientLevelOfEnergy,
		clientLevelOfPatience,
		clientPreviousExperience,
		clientPhysicalAffection
	)VALUES(
		3,
		"Aaron",
		"Ramos-Lazette",
		"",
		"16148005656",
		35,
		1,
		1,
		15,
		350,
		180,
		3,
		3,
		3,
		4,
		4
);

INSERT OR REPLACE INTO Address(
		addressClientID,
		addressStreetLine1,
		addressStreetLine2,
		addressCity,
		addressSubnationalDivision,
		addressCountry,
		addressPostalCode
	)VALUES(
		3,
		"999 Riverrun Crescent",
		"",
		"Toronto",
		"Ontario",
		"Canada",
		"L0D9H8"
);

INSERT OR REPLACE INTO Clients(
		clientID,
		clientFName,
		clientLName,
		clientPrefTitle,
		clientPhoneNumber,
		clientAge,
		clientHasChildrenUnderTwelve,
		clientHasPets,
		clientLengthOfOwnershipExpectation,
		clientMonthlyBudgetForAnimal,
		clientAvailabilityPerDay,
		clientLevelOfMobility,
		clientLevelOfEnergy,
		clientLevelOfPatience,
		clientPreviousExperience,
		clientPhysicalAffection
	)VALUES(
		4,
		"Barbara",
		"Smith",
		"Ms.",
		"6131114200",
		53,
		1,
		0,
		8,
		50,
		30,
		2,
		4,
		1,
		1,
		4
);

INSERT OR REPLACE INTO Address(
		addressClientID,
		addressStreetLine1,
		addressStreetLine2,
		addressCity,
		addressSubnationalDivision,
		addressCountry,
		addressPostalCode
	)VALUES(
		4,
		"18 Prince of Wales",
		"Floor 15/Apartment 34",
		"Ottawa",
		"Ontario",
		"Canada",
		"Q0A6D6"
);

INSERT OR REPLACE INTO Species(
		speciesName
	)VALUES(
		"Cat"
);

INSERT OR REPLACE INTO Breeds(
		speciesName,
		breedName
	)VALUES(
		"Cat",
		"Tabby"
);

INSERT OR REPLACE INTO Animals(
		shelterID,
		animalName,
		animalSpecies,
		animalBreed,
		animalAge,
		animalSex,
		animalLevelOfCare,
		animalEstimatedCostPerMonth,
		animalTrainingLevel,
		animalTrainabilityLevel,
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
		2,
		15,
		1,
		0,
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

INSERT OR REPLACE INTO Animals(
		shelterID,
		animalName,
		animalSpecies,
		animalBreed,
		animalAge,
		animalSex,
		animalLevelOfCare,
		animalEstimatedCostPerMonth,
		animalTrainingLevel,
		animalTrainabilityLevel,
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
		0,
		15,
		1,
		0,
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
INSERT OR REPLACE INTO Animals(
		shelterID,
		animalName,
		animalSpecies,
		animalBreed,
		animalAge,
		animalSex,
		animalLevelOfCare,
		animalEstimatedCostPerMonth,
		animalTrainingLevel,
		animalTrainabilityLevel,
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
		20,
		2,
		1,
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

INSERT OR REPLACE INTO Animals(
		shelterID,
		animalName,
		animalSpecies,
		animalBreed,
		animalAge,
		animalSex,
		animalLevelOfCare,
		animalEstimatedCostPerMonth,
		animalTrainingLevel,
		animalTrainabilityLevel,
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
		1,
		30,
		0,
		2,
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

INSERT OR REPLACE INTO Animals(
		shelterID,
		animalName,
		animalSpecies,
		animalBreed,
		animalAge,
		animalSex,
		animalLevelOfCare,
		animalEstimatedCostPerMonth,
		animalTrainingLevel,
		animalTrainabilityLevel,
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
		0,
		10,
		1,
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
		"likes everbody"
);

end transaction;
