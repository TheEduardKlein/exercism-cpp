#include <array>
#include <string>
#include <vector>
#include <algorithm>

// Round down all provided student scores.
std::vector<int> round_down_scores(std::vector<double> student_scores) {

    std::vector<int> round_down_scores {};
    for (double score : student_scores)
        round_down_scores.emplace_back(static_cast<int>(score));
    
    return round_down_scores;
    
}

// Count the number of failing students out of the group provided.
int count_failed_students(std::vector<int> scores) {
    // TODO: Implement count_failed_students
    int c = std::count_if(scores.begin(), scores.end(), [](int x) { return x <= 40; });
    return c;
}

// Create a list of grade thresholds based on the provided highest grade.
std::array<int, 4> letter_grades(int highest_score) {
    
    int steps = (highest_score - 40) / 4;

    std::array<int, 4> a {41, 41 + steps, 41 + steps*2, 41 + steps*3};

    return a;
}

// Organize the student's rank, name, and grade information in ascending order.
std::vector<std::string> student_ranking(
    std::vector<int> student_scores, std::vector<std::string> student_names) {
    
    //return format: "<rank>. <student name>: <student score>"
    //input scores are ranked high -> low

    std::vector<std::string> organized {};

    for (int i{0}; i < student_scores.size(); ++i) {
        std::string rank = std::to_string(i + 1) + ". ";
        std::string name = student_names[i] + ": ";
        std::string score = std::to_string(student_scores[i]);
        organized.emplace_back(rank + name + score);        
    }

    return organized;
}

// Create a string that contains the name of the first student to make a perfect
// score on the exam.
std::string perfect_score(std::vector<int> student_scores,
                          std::vector<std::string> student_names) {
    // return first name as string of student with 100 score, if none return ""
    
    for (int i{}; i < student_scores.size(); ++i) 
        if (student_scores[i] == 100) return student_names[i];

    return "";
}
