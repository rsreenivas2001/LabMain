CREATE TABLE `users` (
  `FirstName` varchar(45) NOT NULL,
  `MiddleName` varchar(45) NOT NULL,
  `LastName` varchar(45) NOT NULL,
  `FatherName` varchar(45) NOT NULL,
  `Occupation` varchar(45) NOT NULL,
  `DOB` date DEFAULT NULL,
  `Aadhar` int NOT NULL,
  PRIMARY KEY (`Aadhar`)
) ;

CREATE TABLE `visited_places` (
  `id` int NOT NULL AUTO_INCREMENT,
  `user_aadhar` int DEFAULT NULL,
  `EntryTime` varchar(45) DEFAULT NULL,
  `ExitTime` varchar(45) DEFAULT NULL,
  `Place` varchar(45) DEFAULT NULL,
  `Date` date NOT NULL,
  PRIMARY KEY (`id`),
  KEY `user_aadhar_id_idx` (`user_aadhar`),
  CONSTRAINT `user_aadhar_id` FOREIGN KEY (`user_aadhar`) REFERENCES `users` (`Aadhar`)
) ;

CREATE TABLE `warning` (
  `aadhar` int NOT NULL,
  PRIMARY KEY (`aadhar`),
  CONSTRAINT `aadhar` FOREIGN KEY (`aadhar`) REFERENCES `users` (`Aadhar`)
) ;

CREATE TABLE `covid_pos` (
  `aadhar` int NOT NULL,
  `status` tinyint DEFAULT NULL,
  PRIMARY KEY (`aadhar`),
  CONSTRAINT `aadhar_user` FOREIGN KEY (`aadhar`) REFERENCES `users` (`Aadhar`) ON DELETE CASCADE ON UPDATE CASCADE
) ;

CREATE TABLE `auth` (
  `idauth` int NOT NULL AUTO_INCREMENT,
  `username` int DEFAULT NULL,
  `password` varchar(45) DEFAULT NULL,
  PRIMARY KEY (`idauth`),
  KEY `user_aadhar_auth_idx` (`username`),
  CONSTRAINT `user_aadhar_auth` FOREIGN KEY (`username`) REFERENCES `users` (`Aadhar`)
) ;

CREATE TABLE `hospitals` (
  `hid` int NOT NULL AUTO_INCREMENT,
  `name` varchar(45) NOT NULL,
  `city` varchar(45) NOT NULL,
  PRIMARY KEY (`hid`)
) ;

CREATE TABLE `medoffcials` (
  `hid` int NOT NULL,
  `name` varchar(45) NOT NULL,
  `aadhar` int NOT NULL,
  `dob` date NOT NULL,
  PRIMARY KEY (`aadhar`),
  KEY `hid_foreign_key_idx` (`hid`),
  KEY `aadhar_idx` (`aadhar`),
  CONSTRAINT `hid_foreign_key` FOREIGN KEY (`hid`) REFERENCES `hospitals` (`hid`) ON DELETE CASCADE ON UPDATE CASCADE
) ;

CREATE TABLE `mauth` (
  `idmauth` int NOT NULL AUTO_INCREMENT,
  `username` int NOT NULL,
  `password` varchar(45) NOT NULL,
  PRIMARY KEY (`idmauth`),
  KEY `user_idx` (`username`),
  CONSTRAINT `user_aadhar_mauth` FOREIGN KEY (`username`) REFERENCES `medoffcials` (`aadhar`)
) ;


DELIMITER $$
CREATE DEFINER=`root`@`localhost` FUNCTION `getPositiveCount`() RETURNS int
    DETERMINISTIC
BEGIN
    DECLARE finished INTEGER DEFAULT 0;
    DECLARE covidStatus TINYINT;
    DECLARE posCount INTEGER DEFAULT 0;
    DECLARE curPos CURSOR FOR SELECT status FROM covid_pos;
    DECLARE CONTINUE HANDLER FOR NOT FOUND SET finished = 1;

    OPEN curPos;

    getPos: LOOP
        FETCH curPos INTO covidStatus;
        IF finished = 1 THEN
            LEAVE getPos;
        end if ;
        IF covidStatus = 1 THEN
            SET posCount = posCount + 1;
        end if ;
    end loop ;
    CLOSE curPos;

RETURN posCount;

end$$
DELIMITER ;

CREATE DEFINER=`root`@`localhost` TRIGGER `covid_pos_AFTER_INSERT` AFTER INSERT ON `covid_pos` FOR EACH ROW BEGIN
	 DECLARE posEntry VARCHAR(45);
        DECLARE finished INTEGER DEFAULT 0;
        DECLARE userAadhar INT;
        DECLARE userEntryTime VARCHAR(45);
        DECLARE visStatus CURSOR FOR SELECT user_aadhar,EntryTime FROM visited_places;
        DECLARE CONTINUE HANDLER FOR NOT FOUND SET finished = 1;
        SET posEntry = (SELECT EntryTime FROM visited_places WHERE user_aadhar = new.aadhar);
        IF NEW.status = 1 THEN
            OPEN visStatus;

            getStatus: LOOP
                FETCH visStatus INTO userAadhar,userEntryTime;
                IF finished = 1 THEN
                    LEAVE getStatus;
                end if ;
                IF userEntryTime = posEntry THEN
					if userAadhar = new.aadhar then
						iterate getStatus;
					end if;
                    INSERT INTO warning VALUES (userAadhar);
                end if ;
            end loop ;
            CLOSE visStatus;

        end if ;
END

#queries:

SELECT * FROM auth WHERE username=%s AND password=SHA1(%s),tupule

INSERT INTO users (`FirstName`, `MiddleName`, `LastName`, `FatherName`, `Occupation`, `DOB`, `Aadhar`)  VALUES (%s,%s,%s,%s,%s,%s,%s),tuple

INSERT INTO auth ( `username`, `password`) VALUES (%s,SHA1(%s)),auth

INSERT INTO visited_places (`user_aadhar`,`EntryTime`, `ExitTime`, `Place`,`Date`) VALUES (%s,%s,%s,%s,CURDATE()),data

SELECT * FROM mauth WHERE username=%s AND password=SHA1(%s),tupule

select EntryTime,ExitTime,Place from visited_places where user_aadhar='%s',user

select status from covid_pos where aadhar=%d % (data,)

select * from covid_pos where aadhar=%d % (data,)

update covid_pos set status=1 where aadhar=%d % (data,)

insert into covid_pos values (%d,1) % (data,)

insert into covid_pos values ('%d',1); % (data,)

select * from covid_pos where aadhar=%d % (data,)

update covid_pos set status=0 where aadhar=%d % (data,)

select getPositiveCount()

select getNegativeCount()

select * from warning where aadhar=%d % (data,)




