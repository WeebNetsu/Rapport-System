CREATE TABLE `tblStudents` (
	`student_id` INT NOT NULL AUTO_INCREMENT,
	`name` varchar(30) NOT NULL,
	`surname` varchar(50) NOT NULL,
	`grade` INT NOT NULL,
	PRIMARY KEY (`student_id`)
);

CREATE TABLE `tblSubjects` (
	`student_id` INT NOT NULL,
	`math` BOOLEAN NOT NULL DEFAULT false,
	`math_literacy` BOOLEAN NOT NULL DEFAULT false,
	`information_technology` BOOLEAN NOT NULL DEFAULT false,
	`physical_sciences` BOOLEAN NOT NULL DEFAULT false,
	`life_sciences` BOOLEAN NOT NULL DEFAULT false,
	`engineering_and_graphics_design` BOOLEAN NOT NULL DEFAULT false,
	`history` BOOLEAN NOT NULL DEFAULT false,
	`geography` BOOLEAN NOT NULL DEFAULT false,
	`art` BOOLEAN NOT NULL DEFAULT false,
	`music` BOOLEAN NOT NULL DEFAULT false,
	`business` BOOLEAN NOT NULL DEFAULT false,
	`computer_sciences` BOOLEAN NOT NULL DEFAULT false,
	PRIMARY KEY (`student_id`)
);

CREATE TABLE `tblMarks` (
	`student_id` INT NOT NULL,
	`afrikaans` INT NOT NULL DEFAULT '0',
	`english` INT NOT NULL DEFAULT '0',
	`life_ orientation` INT NOT NULL DEFAULT '0',
	`math` INT,
	`math_literacy` INT,
	`information_technology` INT,
	`physical _sciences` INT,
	`life_sciences` INT,
	`engineering_and_graphics_design` INT,
	`history` INT,
	`geography` INT,
	`art` INT,
	`music` INT,
	`business` INT,
	`computer_sciences` INT,
	PRIMARY KEY (`student_id`)
);

ALTER TABLE `tblSubjects` ADD CONSTRAINT `tblSubjects_fk0` FOREIGN KEY (`student_id`) REFERENCES `tblStudents`(`student_id`);

ALTER TABLE `tblMarks` ADD CONSTRAINT `tblMarks_fk0` FOREIGN KEY (`student_id`) REFERENCES `tblStudents`(`student_id`);

INSERT INTO tblStudents(name, surname, grade) VALUES("Tim", "Baker", 8);
INSERT INTO tblStudents(name, surname, grade) VALUES("Neil", "Jacket", 10);
INSERT INTO tblStudents(name, surname, grade) VALUES("Jarrod", "Lorius", 11);
INSERT INTO tblStudents(name, surname, grade) VALUES("Gale", "Sneaker", 9);
INSERT INTO tblStudents(name, surname, grade) VALUES("Jack", "Nightgale", 12);

INSERT INTO tblSubjects(student_id, math, physical_sciences, life_sciences, history, geography) VALUES(1, true, true, true, true, true); -- grade 8
INSERT INTO tblSubjects(student_id, math_literacy, information_technology, engineering_and_graphics_design, art) VALUES(2, true, true, true, true);
INSERT INTO tblSubjects(student_id, math, music, business, computer_sciences) VALUES(3, true, true, true, true);
INSERT INTO tblSubjects(student_id, math, physical_sciences, life_sciences, history, geography) VALUES(4, true, true, true, true, true); -- grade 9
INSERT INTO tblSubjects(student_id, math_literacy, physical_sciences, life_sciences, geography) VALUES(5, true, true, true, true);