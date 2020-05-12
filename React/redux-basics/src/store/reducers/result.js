import * as actionTypes from '../actions/actionTypes';
import { updateObject } from '../utility';

const initialState = {
  results: [],
};

const deleteResult = (state, action) => {
  const updatedArray = state.results.filter(result => result.id !== action.resultElId); // filter 도 새로운 array 를 만들어줌.
  return updateObject(state, {results: updatedArray});
};

const reducer = (state=initialState, action) => {
  switch (action.type) {
    case actionTypes.STORE_RESULT:
      return updateObject(state, {results: state.results.concat({id: new Date(), value: action.result})}); // concat 은 새로운 array 를 만들어내기 때문에 immutable 하다. (push 절대 쓰면 안됨)
    case actionTypes.DELETE_RESULT:
      return deleteResult(state, action);
  }
  return state;
};

export default reducer;
