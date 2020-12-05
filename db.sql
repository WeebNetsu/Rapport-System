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
	`afrikaans` BOOLEAN NOT NULL DEFAULT false,
	`afrikaans_fal` BOOLEAN NOT NULL DEFAULT false,
	`english` BOOLEAN NOT NULL DEFAULT false,
	`english_fal` BOOLEAN NOT NULL DEFAULT false,
	`life_orientation` BOOLEAN NOT NULL DEFAULT false,
	PRIMARY KEY (`student_id`)
);

CREATE TABLE `tblMarks` (
	`student_id` INT NOT NULL,
	`afrikaans` INT DEFAULT 0,
	`afrikaans_fal` INT DEFAULT 0,
	`english` INT DEFAULT 0,
	`english_fal` INT DEFAULT 0,
	`math` INT DEFAULT 0,
	`math_literacy` INT DEFAULT 0,
	`life_orientation` INT DEFAULT 0,
	`information_technology` INT DEFAULT 0,
	`physical_sciences` INT DEFAULT 0,
	`life_sciences` INT DEFAULT 0,
	`engineering_and_graphics_design` INT DEFAULT 0,
	`history` INT DEFAULT 0,
	`geography` INT DEFAULT 0,
	`art` INT DEFAULT 0,
	`music` INT DEFAULT 0,
	`business` INT DEFAULT 0,
	`computer_sciences` INT DEFAULT 0,
	PRIMARY KEY (`student_id`)
);

ALTER TABLE `tblSubjects` ADD CONSTRAINT `tblSubjects_fk0` FOREIGN KEY (`student_id`) REFERENCES `tblStudents`(`student_id`);

ALTER TABLE `tblMarks` ADD CONSTRAINT `tblMarks_fk0` FOREIGN KEY (`student_id`) REFERENCES `tblStudents`(`student_id`);


INSERT INTO tblStudents(name, surname, grade) VALUES("Tim", "Baker", 8);
INSERT INTO tblStudents(name, surname, grade) VALUES("Neil", "Jacket", 10);
INSERT INTO tblStudents(name, surname, grade) VALUES("Jarrod", "Lorius", 11);
INSERT INTO tblStudents(name, surname, grade) VALUES("Gale", "Sneaker", 9);
INSERT INTO tblStudents(name, surname, grade) VALUES("Jack", "Nightgale", 12);


INSERT INTO tblSubjects(student_id, math, physical_sciences, life_sciences, history, geography, afrikaans_fal, english) VALUES(1, true, true, true, true, true, true, true); -- grade 8
INSERT INTO tblSubjects(student_id, math_literacy, information_technology, engineering_and_graphics_design, art, afrikaans, english) VALUES(2, true, true, true, true, true, true);
INSERT INTO tblSubjects(student_id, math, music, business, computer_sciences, afrikaans, english_fal) VALUES(3, true, true, true, true, true, true);
INSERT INTO tblSubjects(student_id, math, physical_sciences, life_sciences, history, geography, afrikaans_fal, english) VALUES(4, true, true, true, true, true, true, true); -- grade 9
INSERT INTO tblSubjects(student_id, math_literacy, life_orientation, life_sciences, geography, afrikaans, english) VALUES(5, true, true, true, true, true, true);


INSERT INTO tblMarks(student_id, afrikaans,  math, physical_sciences, life_sciences, history, geography, afrikaans_fal, english) VALUES(1, 56, 50, 45, 70, 60, 64, 68, 71);
INSERT INTO tblMarks(student_id, math_literacy, information_technology, engineering_and_graphics_design, art, afrikaans, english) VALUES(2, 78, 91, 52, 62, 53, 60);
INSERT INTO tblMarks(student_id, math, music, business, computer_sciences, afrikaans, english_fal) VALUES(3, 88, 79, 72, 85, 91, 96);
INSERT INTO tblMarks(student_id, math, physical_sciences, life_sciences, history, geography, afrikaans_fal, english) VALUES(4, 42, 39, 55, 49, 57, 60, 56); -- grade 9
INSERT INTO tblMarks(student_id, math_literacy, life_orientation, life_sciences, geography, afrikaans, english) VALUES(5, 56, 31, 69, 87, 50, 59);