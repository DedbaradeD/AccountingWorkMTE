SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0;
SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0;
SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='TRADITIONAL,ALLOW_INVALID_DATES';

CREATE SCHEMA IF NOT EXISTS `AccountingWorkMTE` DEFAULT CHARACTER SET utf8 COLLATE utf8_general_ci ;
USE `AccountingWorkMTE` ;

-- -----------------------------------------------------
-- Table `AccountingWorkMTE`.`Drivers`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `AccountingWorkMTE`.`Drivers` (
  `idDriver` INT NOT NULL,
  `theInitials` VARCHAR(45) NULL,
  `dateOfBirth` VARCHAR(45) NULL,
  `passportNumber` VARCHAR(45) NULL,
  `driversLicence` VARCHAR(45) NULL,
  `car` VARCHAR(45) NULL,
  PRIMARY KEY (`idDriver`))
ENGINE = InnoDB;


SET SQL_MODE=@OLD_SQL_MODE;
SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS;
SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS;
