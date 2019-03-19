/* Load database */
.open data.db
.read schema.sql

/* Populate database */
begin transaction;


.read populate/populate_species.sql
.read populate/populate_breeds.sql
.read populate/populate_animals.sql
.read populate/populate_clients.sql
.read populate/populate_addresses.sql

end transaction;
