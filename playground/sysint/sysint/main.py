from fastapi import FastAPI, HTTPException
from pydantic import BaseModel, UUID4

from uuid import uuid4

app = FastAPI()


class Question(BaseModel):
    q_id: UUID4
    question: str
    answer: str | None

class QuestionCreate(BaseModel):
    question: str


questions: list[Question] = []

# 127.0.0.1:8000/
@app.get("/")
def read_root():
    return {"message": "Hello World"}

@app.get("/question")
def get_all_questions():
    return questions

@app.post("/question")
def add_question(new_question: QuestionCreate):
    q_id = uuid4()
    created_question = Question(q_id = q_id, question = new_question.question, answer = None)
    questions.append(created_question)
    return created_question

@app.get("/question/{q_id}")
def get_question(q_id: UUID4):
    for question in questions:
        if question.q_id == q_id:
            return question
    raise HTTPException(404, f"Question with id {q_id} not found!")