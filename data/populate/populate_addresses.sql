begin transaction;


INSERT OR REPLACE INTO Address(
		clientID,
		streetLine1,
		streetLine2,
		city,
		subnationalDivision,
		country,
		postalCode
	)VALUES(
		4,
		"18 Prince of Wales",
		"Floor 15/Apartment 34",
		"Ottawa",
		"Ontario",
		"Canada",
		"Q0A6D6"
);

INSERT OR REPLACE INTO Address(
		clientID,
		streetLine1,
		streetLine2,
		city,
		subnationalDivision,
		country,
		postalCode
	)VALUES(
		0,
		"123 Main Street",
		"",
		"Ottawa",
		"Ontario",
		"Canada",
		"A0A1B1"
);

INSERT OR REPLACE INTO Address(
		clientID,
		streetLine1,
		streetLine2,
		city,
		subnationalDivision,
		country,
		postalCode
	)VALUES(
		1,
		"321 Nighthawk Avenue",
		"",
		"Ottawa",
		"Ontario",
		"Canada",
		"C2C0A0"
);

INSERT OR REPLACE INTO Address(
		clientID,
		streetLine1,
		streetLine2,
		city,
		subnationalDivision,
		country,
		postalCode
	)VALUES(
		2,
		"1888 Long Street",
		"Room Number 144",
		"Ottawa",
		"Ontario",
		"Canada",
		"N6M0L2"
);

INSERT OR REPLACE INTO Address(
		clientID,
		streetLine1,
		streetLine2,
		city,
		subnationalDivision,
		country,
		postalCode
	)VALUES(
		3,
		"999 Riverrun Crescent",
		"",
		"Toronto",
		"Ontario",
		"Canada",
		"L0D9H8"
);

end transaction;
