#include "initdb.h"

QSqlDatabase getDB(){
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("gymgg.db");
    db.exec("PRAGMA foreign_keys = ON");
    if (!db.open()){
        throw db.lastError().text();
    }
    return db;
}


bool initDB(){
    return createTables() && createDefaultWorkoutTemplates() && createDefaultExercises();
}


bool createTables(){
    QSqlDatabase db = getDB();
    QSqlQuery query(db);
    bool creation_success = true;
    // Users Table
    query.prepare("CREATE TABLE IF NOT EXISTS Users ("
                  "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                  "username TEXT UNIQUE NOT NULL,"
                  "email TEXT UNIQUE NOT NULL,"
                  "password TEXT NOT NULL,"
                  "salt TEXT NOT NULL," // for password hashing
                  "birthdate DATE,"
                  "weights TEXT DEFAULT '{}'," // stringified json object {created_at: weight (kg)}
                  "height INTEGER," // in cm
                  "gender TEXT DEFAULT 'unspecified',"
                  "goal TEXT DEFAULT 'unspecified'," // custom or default value
                  "created_at DATETIME NOT NULL"
                  ");");
    if (!query.exec()){
        creation_success = false;
        db.rollback();
    }
    // Exercises Table
    if (creation_success){
        query.prepare("CREATE TABLE IF NOT EXISTS Exercises ("
                      "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                      "name TEXT UNIQUE NOT NULL,"
                      "description TEXT,"
                      "type TEXT DEFAULT 'unspecified'," // strength, cardio, flexibility, etc.
                      "notes TEXT,"
                      "muscles TEXT DEFAULT 'none'," // stringified list of muscles separated by comma (no spaces)
                      "equipments TEXT DEFAULT 'none'," // stringified list of equipments separated by comma (no spaces)
                      "icon TEXT DEFAULT 'default.png'" // icon file name
                      ");");
        if (!query.exec()){
            creation_success = false;
            db.rollback();
        }
    }
    // Workouts Templates Table
    if (creation_success){
        query.prepare("CREATE TABLE IF NOT EXISTS WorkoutTemplates ("
                      "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                      "name TEXT NOT NULL,"
                      "description TEXT,"
                      "notes TEXT,"
                      "type TEXT DEFAULT 'unspecified',"
                      "exercises TEXT NOT NULL DEFAULT '{}'," // stringified json object {exercise_id: {number_of_sets: number_of_reps}}
                      "icon TEXT DEFAULT 'default.png',"
                      "user_id INTEGER NOT NULL," // user who created the template
                      "FOREIGN KEY (user_id) REFERENCES Users(id) ON DELETE CASCADE"
                      ");");
        if (!query.exec()){
            creation_success = false;
            db.rollback();
        }
    }
    // Workouts Table
    if (creation_success){
        query.prepare("CREATE TABLE IF NOT EXISTS Workouts ("
                      "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                      "name TEXT NOT NULL,"
                      "type TEXT DEFAULT 'custom'," // custom,strength,cardio,flexibility, etc.
                      "datetime DATETIME NOT NULL," // start date and time of the workout session
                      "duration INTEGER NOT NULL," // duration of the workout session in seconds
                      "notes TEXT,"
                      "user_id INTEGER NOT NULL," // user who performed the workout
                      "template_id INTEGER," // template used for the workout
                      "completed BOOLEAN DEFAULT 0," // 0 for false, 1 for true
                      "FOREIGN KEY (user_id) REFERENCES Users(id) ON DELETE CASCADE,"
                      "FOREIGN KEY (template_id) REFERENCES WorkoutTemplates(id) ON DELETE CASCADE"
                      ");");
        if (!query.exec()){
            creation_success = false;
            db.rollback();
        }
    }
    // Exercise Workout Table
    if (creation_success){
        query.prepare("CREATE TABLE IF NOT EXISTS ExerciseWorkouts ("
                      "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                      "datetime DATETIME NOT NULL," // start date and time of the exercise
                      "notes TEXT,"
                      "user_id INTEGER NOT NULL,"
                      "workout_id INTEGER NOT NULL,"
                      "exercise_id INTEGER NOT NULL,"
                      "FOREIGN KEY (user_id) REFERENCES Users(id) ON DELETE CASCADE,"
                      "FOREIGN KEY (workout_id) REFERENCES Workouts(id) ON DELETE CASCADE,"
                      "FOREIGN KEY (exercise_id) REFERENCES Exercises(id) ON DELETE CASCADE"
                      ");");
        if (!query.exec()){
            creation_success = false;
            db.rollback();
        }
    }
    // Sets Table
    if (creation_success){
        query.prepare("CREATE TABLE IF NOT EXISTS Sets ("
                      "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                      "datetime DATETIME NOT NULL," // start date and time of the set
                      "type TEXT DEFAULT 'regular'," // regular, drop, super, etc.
                      "reps INTEGER DEFAULT 0,"
                      "weight REAL DEFAULT 0," // in kg
                      "duration INTEGER DEFAULT 0," // in seconds
                      "1RM REAL DEFAULT 0," // one rep max
                      "RPE REAL DEFAULT 0," // rate of perceived exertion
                      "volume REAL DEFAULT 0," // in kg
                      "performed BOOLEAN DEFAULT 0," // 0 for false, 1 for true
                      "user_id INTEGER NOT NULL," // user who performed the set
                      "workout_id INTEGER NOT NULL," // workout where the set was performed
                      "exercise_workout_id INTEGER NOT NULL," // exercise where the set was performed
                      "exercise_id INTEGER NOT NULL," // exercise corresponding to the set
                      "FOREIGN KEY (user_id) REFERENCES Users(id) ON DELETE CASCADE,"
                      "FOREIGN KEY (workout_id) REFERENCES Workouts(id) ON DELETE CASCADE,"
                      "FOREIGN KEY (exercise_workout_id) REFERENCES ExerciseWorkouts(id) ON DELETE CASCADE,"
                      "FOREIGN KEY (exercise_id) REFERENCES Exercises(id) ON DELETE CASCADE"
                      ");");
        if (!query.exec()){
            creation_success = false;
            db.rollback();
        }
    }
    // PRs Table
    if (creation_success){
        query.prepare("CREATE TABLE IF NOT EXISTS PRs ("
                      "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                      "datetime DATETIME NOT NULL," // date and time of the PR
                      "type TEXT NOT NULL DEFAULT 'unspecified',"
                      "value REAL NOT NULL," // in kg or seconds
                      "user_id INTEGER NOT NULL,"
                      "workout_id INTEGER NOT NULL,"
                      "exercise_id INTEGER NOT NULL,"
                      "exercise_workout_id INTEGER NOT NULL,"
                      "set_id INTEGER NOT NULL,"
                      "FOREIGN KEY (user_id) REFERENCES Users(id) ON DELETE CASCADE,"
                      "FOREIGN KEY (workout_id) REFERENCES Workouts(id) ON DELETE CASCADE,"
                      "FOREIGN KEY (exercise_id) REFERENCES Exercises(id) ON DELETE CASCADE,"
                      "FOREIGN KEY (exercise_workout_id) REFERENCES ExerciseWorkouts(id) ON DELETE CASCADE,"
                      "FOREIGN KEY (set_id) REFERENCES Sets(id) ON DELETE CASCADE"
                      ");");
        if (!query.exec()){
            creation_success = false;
            db.rollback();
        }
    }
    // Muscles Table
    if (creation_success){
        query.prepare("CREATE TABLE IF NOT EXISTS Muscles ("
                      "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                      "name TEXT UNIQUE NOT NULL"
                      ");");
        if (!query.exec()){
            creation_success = false;
            db.rollback();
        }
    }
    // Equipments Table
    if (creation_success){
        query.prepare("CREATE TABLE IF NOT EXISTS Equipments ("
                      "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                      "name TEXT UNIQUE NOT NULL"
                      ");");
        if (!query.exec()){
            creation_success = false;
            db.rollback();
        }
    }

    db.close();
    return creation_success;
}


bool createDefaultExercises(){ // TODO
    QSqlDatabase db = getDB();
    db.close();
    return false;
}


bool createDefaultWorkoutTemplates(){ // TODO
    QSqlDatabase db = getDB();
    db.close();
    return false;
}
