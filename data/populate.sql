.open data.db

CREATE TABLE IF NOT EXISTS Animal(
	id INTEGER NOT NULL,
	name text NOT NULL,
	species text NOT NULL,
	breed text NOT NULL,
	age INTEGER NOT NULL,
	lifeExpectancy INTEGER NOT NULL,
	sex char NOT NULL,
	levelOfCare INTEGER NOT NULL,
	levelOfEnergy INTEGER NOT NULL,
	estimatedCostPerMonth INTEGER NOT NULL,
	trainingLevel INTEGER NOT NULL,
	trainabilityLevel INTEGER NOT NULL,
	affinityForPeople INTEGER NOT NULL,
	affinityForChildren INTEGER NOT NULL,
	affinityForAnimals INTEGER NOT NULL,
	approachability INTEGER NOT NULL,
	timeCommitment INTEGER NOT NULL,
	dietNeeds text NOT NULL,
	mobilityNeeds text NOT NULL,
	disablityNeeds text NOT NULL,
	abuseHistory text NOT NULL,
	biography text NOT NULL,

	FOREIGN KEY(breed, species) REFERENCES AnimalBreedRelationship(breedName, speciesName),

	PRIMARY KEY(id)
);

CREATE TABLE IF NOT EXISTS Species(
	name text NOT NULL,

	PRIMARY KEY(name)
);

CREATE TABLE IF NOT EXISTS Breed(
	speciesName text NOT NULL,
	name text NOT NULL,

	FOREIGN KEY(speciesName) REFERENCES Species(name),

	PRIMARY KEY(speciesName, name)
);

CREATE TABLE IF NOT EXISTS AnimalBreedRelationship(
	animalID INTEGER NOT NULL,
	speciesName text NOT NULL,
	breedName text NOT NULL,

	FOREIGN KEY(animalID) REFERENCES Animals(id),
	FOREIGN KEY(speciesName, breedName) REFERENCES Breed(speciesName, name),

	PRIMARY KEY(animalID)
);

/* NO BOOLEANS, 0 is false, 1 is true*/
CREATE TABLE IF NOT EXISTS Client(
	id INTEGER NOT NULL,
	fName text NOT NULL,
	lName text NOT NULL,
	prefTitle text NOT NULL,
	phoneNumber text NOT NULL,
	age INTEGER NOT NULL,
	hasChildrenUnderTwelve INTEGER NOT NULL,
	hasPets INTEGER NOT NULL,
	lengthOfOwnershipExpectation INTEGER NOT NULL,
	monthlyBudgetForAnimal INTEGER NOT NULL,
	availabilityPerDay INTEGER NOT NULL,
	levelOfMobility INTEGER NOT NULL,
	levelOfPatience INTEGER NOT NULL,
	previousExperience INTEGER NOT NULL,
	physicalAffection INTEGER NOT NULL,

	PRIMARY KEY(id)
);

CREATE TABLE IF NOT EXISTS Address(
	clientID INTEGER NOT NULL,
	streetLine1 text NOT NULL,
	streetLine2 text NOT NULL,
	city text NOT NULL,
	subnationalDivision text NOT NULL,
	country text NOT NULL,
	postalCode text NOT NULL,

	FOREIGN KEY(clientID) REFERENCES Client(id),

	PRIMARY KEY(clientID)
);

begin transaction;

.read populate/populate_species.sql
.read populate/populate_breeds.sql
.read populate/populate_animals.sql
.read populate/populate_clients.sql
.read populate/populate_addresses.sql

end transaction;
