~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Description
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

cuACS is responsible for ensuring that sheltered Animals are provided a long-term home that is well suited to them. With that in mind, the Animal Client Matching (ACM) algorithm is responsible for ensuring that Animals are matched with compatible Clients. To do so, the ACM determines a compatibility score for each Animal-Client pair (called a Candidate) and attempts to find Match set (Solution) with the highest mean average for the compatibility scores.

The ACM will attempt to find a suitable Match for all Animals in the shelter and will consider alternate combinations of matches until this requirement is met. However, if the algorithm is forced to choose between matching the Animal with an unsuitable home or keeping the Animal at the shelter until a more compatible home can be found, the algorithm will not choose a home that is not well-suited for the Animal.

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Install & Run Instructions
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Step 1.
	while in the cuACS directory, install using command: make
	
Step 2.
	from the same directory, run using command: ./cuACS
