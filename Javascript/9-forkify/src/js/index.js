import Search from './models/Search';
import * as searchView from './views/searchView';
import { elements, renderLoader, clearLoader } from "./views/base";

/** Global state of the app
 * - Search Object
 * - Current recipe object
 * - Shopping list object
 * - Liked recipes
 */
const state = {};

const controlSearch = async () => {
  // 1) Get query from view
  const query = searchView.getInput();

  if (query) {
    // 2) New search object and add to state
    state.search = new Search(query);

    // 3) Prepare UI for results
    searchView.clearInput();
    searchView.clearResults();
    renderLoader(elements.searchRes);

    // 4) Search for recipes
    await state.search.getResults();

    // 5) Render results on UI
    clearLoader();
    searchView.renderResults(state.search.result);
  }
};

elements.searchForm.addEventListener('submit', e => {
  e.preventDefault();
  controlSearch();
});

elements.searchResPages.addEventListener('click', e => {
  const btn = e.target.closest('.btn-inline'); // element which is the closest ancestor of the selected element (may be null)
  if (btn) {
    const goToPage = parseInt(btn.dataset.goto, 10); // HTML5 에서 data-{} 로 attribute 을 주면 다음과 같이 dataset.{} 로 접근가능
    searchView.clearResults();
    searchView.renderResults(state.search.result, goToPage);
  }
});
