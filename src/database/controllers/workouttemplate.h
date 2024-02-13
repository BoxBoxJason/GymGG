#ifndef DATABASE_CONTROLLERS_WORKOUTTEMPLATES_H
#define DATABASE_CONTROLLERS_WORKOUTTEMPLATES_H

#include "../models/workouttemplate.h"

QString getTemplateJson(int template_id);

bool removeExerciseFromTemplate(int template_id, int exercise_id);
bool removeExerciseFromAllTemplates(int exercise_id);

#endif // DATABASE_CONTROLLERS_WORKOUTTEMPLATES_H
