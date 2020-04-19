import axios from 'axios';

const instance = axios.create({
  baseURL: 'https://react-burger-builder-daf82.firebaseio.com/'
});

export default instance;
